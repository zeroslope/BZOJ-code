/*田忌赛马加强版。
尽可能让最弱的赢，最强的赢，都不行则最弱打最强
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<class T>
inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N,A[100010]={0},B[100010]={0};
inline int DEAL(int a[],int b[]){
	int ans=0;
	int l1=1,l2=1,r1=N,r2=N;
	while(l1<=r1 && l2<=r2){
		if(a[l1]>b[l2]){ ans+=2; l1++; l2++; }
		else if(a[r1]>b[r2]){ ans+=2; r1--; r2--; }
		else { ans+=(a[l1]==b[r2]); l1++; r2--; }
	}	
	return ans;
}

int main(){
	Read(N);
	for(int i=1;i<=N;++i) Read(A[i]);
	for(int i=1;i<=N;++i) Read(B[i]);
	sort(A+1,A+N+1);
	sort(B+1,B+N+1);
	printf("%d %d\n",DEAL(A,B),2*N-DEAL(B,A));
	return 0;
}
