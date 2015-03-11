#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000010 ; 
typedef long long LL;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int n=0,a=0,b=0,c=0;
LL  sum[maxn]={0},f[maxn]={0},g[maxn]={0},Q[maxn]={0};
inline LL sqr(LL x){ return x*x; }
inline double slop(int k,int j){
	return (double)(g[j]-g[k])/(double)(2*a*(sum[j]-sum[k]));
}
int main(){
	Read(n);
	Read(a); Read(b); Read(c);
	for(int i=1;i<=n;++i){
		Read(sum[i]); sum[i]+=sum[i-1];
	}
	int l=0,r=0;
	for(int i=1;i<=n;++i){
		while(l<r && slop(Q[l],Q[l+1])<sum[i]) l++;
		int top=Q[l];
		f[i]=f[top]+a*sqr(sum[i]-sum[top])+b*(sum[i]-sum[top])+c;
		g[i]=f[i]+a*sqr(sum[i])-b*sum[i];
		while(l<r && slop(Q[r-1],Q[r])>slop(Q[r],i)) r--;
		Q[++r]=i;
	}
	printf("%lld\n",f[n]);
	return 0;
}

