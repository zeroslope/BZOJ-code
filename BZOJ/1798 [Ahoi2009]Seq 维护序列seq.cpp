#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=110000;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N; LL P;
#define L(x) (x<<1)
#define R(x) (x<<1|1)
LL  T[MAXN<<2],Mul[MAXN<<2],Add[MAXN<<2];
inline void PushDown(int o,int l,int r){
	int mid=(l+r)>>1;
	T[L(o)]=T[L(o)]*Mul[o]+Add[o]*(mid-l+1); T[L(o)]%=P;
	T[R(o)]=T[R(o)]*Mul[o]+Add[o]*(r-mid  ); T[R(o)]%=P;
	Mul[L(o)]*=Mul[o]; Mul[L(o)]%=P;
	Mul[R(o)]*=Mul[o]; Mul[R(o)]%=P;
	Add[L(o)]=Mul[o]*Add[L(o)]+Add[o]; Add[L(o)]%=P;
	Add[R(o)]=Mul[o]*Add[R(o)]+Add[o]; Add[R(o)]%=P;
	Mul[o]=1; Add[o]=0;
} 
inline void Update(int o){ T[o]=T[L(o)]+T[R(o)]; T[o]%=P; }
inline void Build(int o,int l,int r){
	Mul[o]=1; Add[o]=0;
	if(l==r){ Read(T[o]); return; }
	int mid=(l+r)>>1;
	Build(L(o),l,mid); Build(R(o),mid+1,r);
	Update(o);
}
inline void Edit(int o,int l,int r,int Qx,int Qy,LL v,LL w){
	if(Qx<=l && r<=Qy){
		T[o]=T[o]*v+w*(r-l+1); T[o]%=P;
		Mul[o]*=v; Mul[o]%=P; Add[o]=Add[o]*v+w; Add[o]%=P;
		return;
	}
	PushDown(o,l,r);
	int mid=(l+r)>>1;
	if(Qx<=mid) Edit(L(o),l,  mid,Qx,Qy,v,w);
	if(Qy> mid) Edit(R(o),mid+1,r,Qx,Qy,v,w);
	Update(o);
}
LL Ans=0;
inline void Query(int o,int l,int r,int Qx,int Qy){
	if(Qx<=l && r<=Qy){ Ans+=T[o]; Ans%=P; return; }
	PushDown(o,l,r);
	int mid=(l+r)>>1;
	if(Qx<=mid) Query(L(o),l,  mid,Qx,Qy);
	if(Qy> mid) Query(R(o),mid+1,r,Qx,Qy);
	Update(o);
}
int main(){
	Read(N); Read(P);
	Build(1,1,N);
	int M=0; Read(M);
	int op=0,t=0,g=0,c=0;
	for(int i=1;i<=M;++i){
		Read(op);
		if(op==1){
			Read(t); Read(g); Read(c);
			Edit(1,1,N,t,g,(LL)c,0);
		}
		if(op==2){
			Read(t); Read(g); Read(c);
			Edit(1,1,N,t,g,1,(LL)c);
		}
		if(op==3){
			Read(t); Read(g);
			Ans=0; Query(1,1,N,t,g);
			printf("%lld\n",Ans);
		}
	}
	return 0;
}

