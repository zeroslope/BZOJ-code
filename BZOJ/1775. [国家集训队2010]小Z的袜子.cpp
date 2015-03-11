#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
char cha[5000000],*ptr=cha;
inline int GETCHAR(){ return *ptr++; }
template<class T>
inline void Read(T& x){
	x=0; bool flag=0; char ch=GETCHAR();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=GETCHAR(); break; } ch=GETCHAR();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=GETCHAR(); }
	if(flag) x=-x;
}

int N=0,M=0,BS=0;
int C[50010],cnt[50010],Belong[50010];
LL  Ans=0,Ans2[50010],Ans1[50010];
struct node{
	int l,r,blc,pos;
}E[50010];
bool cmp(const node& a,const node& b){
	if(a.blc==b.blc) return a.r<b.r;
	return a.l<b.l;
}
inline void Plus(int x){
	if(!x) return;
	if(cnt[x]) Ans+=cnt[x];	cnt[x]++;
}
inline void Dele(int x){
	if(!x) return;
	if(cnt[x]) cnt[x]--,Ans-=cnt[x];
}
inline LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	freopen("hose.in", "r", stdin);
	freopen("hose.out", "w", stdout);
	fread(ptr,1,5000000,stdin);
	Read(N); Read(M);
	int BS=550; int now=1,tot=0;
	for(int i=1;i<=N;++i){
		Read(C[i]); Belong[i]=now; tot++;
		if(tot>BS){ now++; tot=0; }
	}
	for(int i=1;i<=M;++i){
		Read(E[i].l); Read(E[i].r);
		E[i].blc=Belong[E[i].l]; E[i].pos=i;
		LL len=(E[i].r-E[i].l+1); Ans2[i]=(len*(len-1))>>1;
	}
	sort(E+1,E+M+1,cmp);
	for(int l=0,r=0,i=1;i<=M;++i){
		while(l>E[i].l) Plus(C[--l]); 
		while(r<E[i].r) Plus(C[++r]);
		while(l<E[i].l) Dele(C[l++]);
		while(r>E[i].r) Dele(C[r--]);
		LL G=gcd(Ans,Ans2[E[i].pos]);
		Ans1[E[i].pos]=Ans/G; Ans2[E[i].pos]=Ans2[E[i].pos]/G;
	}
	for(int i=1;i<=M;++i){
		printf("%lld/%lld\n",Ans1[i],Ans2[i]);
	}
	return 0;
}
