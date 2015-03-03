#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 19940417;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
LL N=0,M=0;
inline LL Sum1(LL a,LL b){ return (LL)(b-a+1)*(a+b)/2%MOD; }
inline LL Sum2(LL x){
	return x*(x+1)%MOD * (2*x+1)%MOD * 3323403 % MOD;
}
inline LL Part1(LL n){
	LL res=0;
	for(LL i=1,p=0;i<=n;i=p+1){
		p=n/(n/i);
		res=( res+n*(p-i+1)%MOD-Sum1(i,p)*(n/i)%MOD )%MOD;
	}
	return (res+MOD)%MOD;
}
int main(){
	Read(N); Read(M);
	LL Ans=Part1(N)*Part1(M)%MOD;
	if(N>M) swap(N,M);
	for(int i=1,p=0;i<=N;i=p+1){
		p=min(N/(N/i),M/(M/i));
		LL s1=N*M%MOD*(p-i+1)%MOD;
		LL s2=(N/i)*(M/i)%MOD*(Sum2(p)-Sum2(i-1)+MOD)%MOD;
		LL s3=(N/i*M+M/i*N)%MOD*Sum1(i,p)%MOD;
		Ans=(Ans-(s1+s2-s3)%MOD+MOD)%MOD;
	}
	printf("%lld\n",Ans);
	return 0;
}
