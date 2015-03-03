/*
byvoid：
设F[i]为不考虑每种硬币的数量限制的情况下，得到面值i的方案数。则状态转移方程为

F[i]=Sum{F[i-C[k]] | i-C[k]>=0 且 k=1..4}

为避免方案重复，要以k为阶段递推，边界条件为F[0]=1，这样预处理的时间复杂度就是O(S)。

接下来对于每次询问，奇妙的解法如下：根据容斥原理，答案为 得到面值S的超过限制的方案数 - 第1种硬币超过限制的方案数 - 第2种硬币超过限制的方案数 - 第3种硬币超过限制的方案数 - 第4种硬币超过限制的方案数 + 第1,2种硬币同时超过限制的方案数 + 第1,3种硬币同时超过限制的方案数 + ...... + 第1,2,3,4种硬币全部同时超过限制的方案数。

当第1种硬币超过限制时，只要要用到D[1]+1枚硬币，剩余的硬币可以任意分配，所以方案数为 F[ S - (D[1]+1)C[1] ]，当且仅当(S - (D[1]+1)C[1])>=0，否则方案数为0。其余情况类似，每次询问只用问16次，所以询问的时间复杂度为O(1)。	
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXV = 1010;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
LL Ans=0,F[100005];
int T=0,c[5],d[5];
inline void DFS(int x,int k,int sum){
	if(sum<0) return;
	if(x==5){
		if(k&1) Ans-=F[sum];
		else Ans+=F[sum];
		return;
	} 
	DFS(x+1,k+1,sum-(d[x]+1)*c[x]);
	DFS(x+1,k,sum);
}
int main(){
	for(int i=1;i<=4;++i) Read(c[i]);
	Read(T); F[0]=1;
	for(int i=1;i<=4;++i){
		for(int j=c[i];j<=100000;++j){
			F[j]+=F[j-c[i]];
		}
	}
	int x=0;
	for(int i=1;i<=T;++i){
		for(int k=1;k<=4;++k) Read(d[k]);
		Read(x); Ans=0;
		DFS(1,0,x); 
		printf("%lld\n",Ans);

	}
	return 0;
}
