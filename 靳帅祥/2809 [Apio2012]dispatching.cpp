#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100005 ; 
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
struct heap{
	int v,l,r,deep;
}H[maxn];
int cnt_heap=0;
struct node{
	int to,next;
}E[maxn];
int line[maxn],tot=0;
inline void Insert(int x,int y){
	tot++; E[tot].to=y; E[tot].next=line[x]; line[x]=tot;
}
struct tree_node{
	int cost,l,root;
	LL sum,sz;
}T[maxn];
int n,m;
LL  ans=0;
inline int new_heap(int x){
	H[++cnt_heap].v=x;
	H[cnt_heap].l=H[cnt_heap].r=H[cnt_heap].deep=0;
	return cnt_heap;
}
inline int Merge(int x,int y){
	if(!x || !y) return x+y;
	if(H[x].v < H[y].v) swap(x,y);
	H[x].r = Merge(H[x].r,y);
	if(H[H[x].l].deep < H[H[x].r].deep) swap(H[x].l,H[x].r);
	H[x].deep = H[H[x].r].deep+1;
	return x; 
}
inline int  top(int p ){ return H[p].v; }
inline void pop(int &p){ p = Merge(H[p].l,H[p].r); }
inline void DFS(int p){
	int x=0,y=0;
	T[p].root = new_heap(T[p].cost);
	T[p].sum = T[p].cost; T[p].sz = 1;
	for(int i = line[p]; i!=0 ;i = E[i].next){
		y=E[i].to; DFS(y);
		T[p].sum += T[y].sum; T[p].sz += T[y].sz;
		T[p].root = Merge(T[p].root,T[y].root);
	}
	while(T[p].sum > m){
		T[p].sum -= top(T[p].root); pop(T[p].root);
		--T[p].sz;
	}
	ans = max (ans , T[p].sz*T[p].l );
}
int main(){
	Read(n); Read(m);
	int x=0;
	for(int i = 1; i<=n ;++i){
		Read(x); Insert(x,i);
		Read(T[i].cost); Read(T[i].l);
	}
	DFS(1);
	printf("%lld\n",ans);
	return 0;
}

