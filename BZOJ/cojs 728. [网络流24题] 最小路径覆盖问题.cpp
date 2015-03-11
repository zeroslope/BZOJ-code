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
struct node{
	int to,next;
}E[15000];
int line[15000],tot=0;
inline void Insert(int x,int y){
	tot++; E[tot].to=y; E[tot].next=line[x]; line[x]=tot;
}
int pre[15000],N,M;
bool flag[15000];
inline bool KM(int x){
	int p=0;
	for(int i=line[x];i!=0;i=E[i].next){
		p=E[i].to;
		if(!flag[p]){
			flag[p]=true;
			if(pre[p]==-1 || KM(pre[p])){
				pre[p]=x; return true;
			}
		}
	}
	return false;
}
int color[15000];
inline void find(int u,int clr){
	for(int i=line[u];i!=0;i=E[i].next){
		int p=E[i].to;
		if(color[p]==0 && pre[p]==u){
			if(p> N) p-=N;
			color[p]=clr; find(p,clr);
		}
	}
}
int main(){
	freopen("path3.in","r",stdin);
	freopen("path3.out","w",stdout);
	Read(N) ;Read(M);
	int x=0,y=0;
	for(int i=1;i<=M;++i){
		Read(x); Read(y); Insert(x,N+y);
	}
	int Ans=N;
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=N;++i){
		memset(flag,0,sizeof(flag));
		if(KM(i)) Ans--;
	}
	int cnt=0;
	memset(color,0,sizeof(color));
	for(int i=1;i<=N;++i){
		if(pre[i]==-1 && color[i]==0){
			color[i]=++cnt; find(i,cnt);
		}
	}
	for(int i=1;i<=cnt;++i){
		bool first=true;
		for(int j=1;j<=N;++j){
			if(color[j]==i){
				if(first){ first=false; printf("%d",j); }
				else printf(" %d",j);
			}
		}
		printf("\n");
	}
	printf("%d\n",Ans);
	return 0;
}
