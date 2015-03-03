#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=50010;
template<class T>
inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}

inline void DB(int x){ for(int i=1;i<=x;++i) printf("ER"); printf("\n"); }
int N=0,BS=0,M=0;
int Belong[MAXN]; LL T[MAXN],D[MAXN],Ans=0;
struct data{
	int num,pos,id;
}A[MAXN];
struct node{
	int l,r,blc,pos;
}E[MAXN];
inline LL Insert(int x,int v){	if(x<=0) return 0; for(int i=x;i<=N;i+=i&(-i)) T[i]+=v; }
inline LL Query(int x){ if(x<=0) return 0; int Ans=0; for(int i=x;i>0;i-=i&(-i)) Ans+=T[i]; return Ans; }
inline bool cmp1(data a,data b){ return a.num<b.num; }
inline bool cmp2(data a,data b){ return a.pos<b.pos; }
inline bool cmp3(node a,node b){ if(a.blc==b.blc) return a.r<b.r; else return a.l<b.l; }
int main(){
	//freopen("1.in","r",stdin);
	Read(N);
	BS=sqrt(N); int now=1,tot=0;
	for(int i=1;i<=N;++i){
		Read(A[i].num); Belong[i]=now; A[i].pos=i; tot++;
		if(tot>BS){ now++; tot=0; }
	}
	//DB(1);
	sort(A+1,A+N+1,cmp1); 
	A[1].id=1; int cnt=1;
	for(int i=2;i<=N;++i){//离散化
		if(A[i].num==A[i-1].num) A[i].id=cnt;
		else A[i].id=++cnt;
	}
	cnt=0; 
	//DB(2);
	Read(M);
	for(int i=1;i<=M;++i){
		Read(E[i].l); Read(E[i].r); 
		E[i].pos=i; E[i].blc=Belong[E[i].l];
	}
	int p=0;
	sort(E+1,E+M+1,cmp3); sort(A+1,A+N+1,cmp2);
	//DB(3);
	for(int l=0,r=0,i=1;i<=M;++i){
		while(l>E[i].l){ p=A[--l].id; Ans+=Query(p-1); Insert(p,1); } 
		while(r<E[i].r){ p=A[++r].id; Ans+=Query(N)-Query(p); Insert(p,1);}
		while(l<E[i].l){ p=A[l++].id; Ans-=Query(p-1); Insert(p,-1); }
		while(r>E[i].r){ p=A[r--].id; Ans-=( Query(N)-Query(p) ); Insert(p,-1); }
		D[E[i].pos]=Ans;
	}
	for(int i=1;i<=M;++i) printf("%d\n",D[i]);
	return 0;
}
