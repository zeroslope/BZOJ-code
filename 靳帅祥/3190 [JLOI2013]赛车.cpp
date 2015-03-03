#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=500010;
template<class T>
inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N=0,vis[MAXN],top,st[MAXN];
struct node{
	double x,y; int id;
}P[MAXN];
inline bool cmp(const node a,const node b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
inline double Slope(const int x,const int y){ return (double)(P[x].y-P[y].y)/(P[y].x-P[x].x); }
inline void Insert(int x){
	while(top>0){
		if(abs(P[st[top]].x-P[x].x)<=1e-10) top--;
		else if(top>1 && Slope(x,st[top])<=Slope(st[top],st[top-1])) top--;
		else break;
	}
	st[++top]=x;
}
int main(){
	Read(N);
	for(int i=1;i<=N;++i){
		scanf("%lf",&P[i].y); P[i].id=i;
	}
	for(int i=1;i<=N;++i){
		scanf("%lf",&P[i].x);
	}
	sort(P+1,P+N+1,cmp);
	for(int i=1;i<=N;++i) Insert(i);
	for(int i=1;i<=top;++i) vis[P[st[i]].id]=1;
	for(int i=1;i<=N;++i) if(vis[i]) printf("%d ",i);
	return 0;
}
