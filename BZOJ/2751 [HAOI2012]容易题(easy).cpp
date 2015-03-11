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

const LL MOD=1000000007LL;
LL N=0,M=0,K=0;
struct node{
	int x,y;
	bool operator < (const node&  b) const {
		if(x==b.x) return y<b.y;
		return x<b.x;
	}
}E[200010];

inline LL QuickPow(LL a,int k){
	a%=MOD; LL Ans=1;
	while(k>0){
		if(k&1) Ans*=a,Ans%=MOD;
		a*=a; a%=MOD; k>>=1;
	}
	return Ans;
}

int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	
	Read(N); Read(M); Read(K);

	int x=0,y=0;
	for(int i=1;i<=K;++i) Read(E[i].x),Read(E[i].y);
	sort(E+1,E+K+1);
	LL Ans = 1 , T = ( (1+N)*N/2 ) % MOD ;
	LL Tot = M , Tmp = T;

	for(int i = 1 ; i <= K ; ++ i){
		if(E[i].x != E[i-1].x && i!=1){
			Ans=Ans*Tmp; Ans%=MOD; Tmp=T; Tot--;
		}
		if(E[i].x != E[i-1].x || E[i].y != E[i-1].y){
			Tmp-=E[i].y;
			if(Tmp<0) Tmp+=MOD;
		}
	}
	Tot--; Ans=Ans*Tmp%MOD;
		
	LL Res=QuickPow(T,Tot);
	Res%=MOD; Ans%=MOD;
	printf("%lld\n",(Ans*Res)%MOD);
	
	return 0;
}
