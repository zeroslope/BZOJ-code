#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
struct node{
	LL x,y; int num;
}A[MAXN];
int N;
LL sx,sy,ax[MAXN],ay[MAXN],bx[MAXN],by[MAXN];
inline bool cmpx(node a,node b){ return a.x<b.x; }
inline bool cmpy(node a,node b){ return a.y<b.y; }
int main(){
	Read(N);
	LL x=0,y=0;
	for(int i=1;i<=N;++i){
		Read(x); Read(y);
		A[i].x=x+y; A[i].y=x-y;
	}
	sort(A+1,A+N+1,cmpy);
	for(int i=1;i<=N;++i){
		ay[i]=ay[i-1]+A[i].y;
		by[N-i+1]=by[N-i+2]-A[N-i+1].y;
		A[i].num=i;
	}
	for(int i=1;i<=N;++i){
		printf("%d %d ",ay[i],by[i]);
	}
	printf("\n");
	sort(A+1,A+N+1,cmpx);
	for(int i=1;i<=N;++i){
		ax[i]=ax[i-1]+A[i].x;
		bx[N-i+1]=bx[N-i+2]-A[N-i+1].x;
	}
	LL Ans=0x7f7f7f7f7f7f7f7f;
	for(int i=1;i<=N;++i){
		LL tmp=0;
		tmp+=ax[N]-ax[i]-(N-i)*(ax[i]-ax[i-1]);
		tmp+=bx[1]-bx[i]-(i-1)*(bx[i]-bx[i+1]);
		int j=A[i].num;
		tmp+=ay[N]-ay[j]-(N-j)*(ay[j]-ay[j-1]);
		tmp+=by[1]-by[j]-(j-1)*(by[j]-by[j+1]);
		if(Ans>tmp) Ans=tmp;
	}
	printf("%lld",Ans/2);
	return 0;
}

