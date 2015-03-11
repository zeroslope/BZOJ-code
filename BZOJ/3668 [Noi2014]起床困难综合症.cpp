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
int N=0,M=0;
int op[100010]={0},D[100010]={0},F[32]={0};
inline int CALC(int x){
	for(int i=1;i<=N;++i){
		if(op[i]==1) x=(x&D[i]);
		else if(op[i]==2) x=(x|D[i]);
		else x=(x^D[i]);
	}
	return x;
}
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	Read(N); Read(M);
	char ch[10];
	for(int i=1;i<=N;++i){
		scanf("%s",ch); 
		if(ch[0]=='A') op[i]=1;
		else if(ch[0]=='O') op[i]=2;
		else op[i]=3;
		Read(D[i]);
	}
	int tmp=CALC(0);
	for(int i=0;i<=30;++i) F[i]=CALC(1<<i)&(1<<i);
	int Ans=0,tot=0;
	for(int i=30;i>=0;--i){
		if((1<<i)&tmp) Ans+=(1<<i);
		else{
			if(tot+(1<<i)<=M && F[i]) tot+=F[i],Ans+=F[i];
		}
	}
	printf("%d\n",Ans);
	return 0;
}
