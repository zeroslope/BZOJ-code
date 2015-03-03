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
int  n=0,m=0,ans1=0,ans2=0,top=0;
int  f[2010][2010],s[2010],w[2010];
bool map[2010][2010];
inline int sqr(int x){ return x*x; } 
inline void Init1(){
	Read(n); Read(m);
	int a=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			Read(a);
			if( (i&1)==(j&1) && a  ||  (i&1)!=(j&1) && !a ) map[i][j]=1;
			else map[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(map[i][j]) f[i][j]=f[i][j-1]+1;
			else f[i][j]=0;
}
inline void Init2(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			map[i][j]=!map[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(map[i][j]) f[i][j]=f[i][j-1]+1;
			else f[i][j]=0;
}
inline void DEAL(){
	for(int j=1;j<=m;++j){
		top=0;
		for(int i=1;i<=n+1;++i){
			int minw=i;
			while(top && s[top]>=f[i][j]){
				ans1=max(ans1,s[top]*(i-w[top]));
				ans2=max(ans2,sqr(min(s[top],i-w[top])));
				minw=w[top]; top--;
			}
			s[++top]=f[i][j]; w[top]=minw;
		}	
	}
}
int main(){
	Init1(); DEAL();
	Init2(); DEAL();
	printf("%d\n%d\n",ans2,ans1);
	return 0;
}

