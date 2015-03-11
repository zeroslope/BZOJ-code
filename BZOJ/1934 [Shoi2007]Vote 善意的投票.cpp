#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=1000;
typedef long long LL;
template<class T>
inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N=0,M=0,S=0,T=0;
struct node{
	int to,next,cap;
}E[MAXN*MAXN];
int line[MAXN],tot=1;
inline void Insert(int x,int y,int v){
	tot++; E[tot].to=y; E[tot].next=line[x]; line[x]=tot; E[tot].cap=v;
	tot++; E[tot].to=x; E[tot].next=line[y]; line[y]=tot; E[tot].cap=0;
}
int Dis[MAXN],cur[MAXN];
queue<int>Q;
inline bool BFS(){
    memset(Dis,0,sizeof(Dis));
    Q.push(S); Dis[S]=1;
    int u=0,p=0;
    while(!Q.empty()){
        u=Q.front(); Q.pop();
        for(int i=line[u];i!=0;i=E[i].next){
            p=E[i].to;
            if(!Dis[p] && E[i].cap){
                Dis[p]=Dis[u]+1; Q.push(p);
            }
        }
    } 
    return Dis[T] == 0 ? 0 : 1;
}
inline int DFS(int u,int a){
    if(u==T || a==0) return a;
    int p=0,f=0,flow=0;
    for(int &i=cur[u];i!=0;i=E[i].next){
        p=E[i].to;
        if(Dis[p]==Dis[u]+1 && E[i].cap>0){
            f=DFS(p,min(a,E[i].cap));
            flow+=f; a-=f;
            E[i].cap-=f; E[i^1].cap+=f;
            if(a==0) break;
        }
    }
    return flow;
}
inline int Dinic(){
    int Ans=0;
    while(BFS()){
        memcpy(cur,line,sizeof(line));
        Ans+=DFS(S,0x3f3f3f3f);
    }
    return Ans;
}
int main(){
	Read(N); Read(M);
	S=N+10; T=S+1; 
	int x=0,y=0;
	for(int i=1;i<=N;++i){
		Read(x);
		if(x==1) Insert(S,i,1);
		else Insert(i,T,1);
	}
	for(int i=1;i<=M;++i){
		Read(x); Read(y);
		Insert(x,y,1); Insert(y,x,1);
	}
	printf("%d\n",Dinic());
	return 0;
}

