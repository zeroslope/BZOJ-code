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
LL N=0,K=0,F[510][510]={0};
inline LL Abs(LL x){ if(x<0) return -x; return x; } 
struct node{
	LL x,y;
}P[5100];
int main(){
	Read(N); Read(K);
	for(int i=1;i<=N;++i){ Read(P[i].x); Read(P[i].y); }
	memset(F,0x3f,sizeof(F));
	F[1][0]=0;
	for(int i=2;i<=N;++i){
		for(int j=0;j< i-1 && j<=K;++j){
			for(int h=i-1;i-h-1<=j && h;--h){
				F[i][j]=min(F[i][j],F[h][j-(i-h-1)]+Abs(P[i].x-P[h].x)+Abs(P[i].y-P[h].y));
			}
		}
	}
	LL Ans=0x7f7f7f7f7f7f7f;
	for(int i=0;i<=K;++i) Ans=min(Ans,F[N][i]);
	printf("%lld\n",Ans);
	return 0;
}

