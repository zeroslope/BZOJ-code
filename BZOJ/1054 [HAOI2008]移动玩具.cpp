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
inline int GETCHAR(){ char ch=getchar(); while(ch!='0' && ch!='1') ch=getchar(); return ch-48; }
int E[4][4],T[4][4];
inline int Abs(int x){ if(x<0) return -x; return x; }
int A[20],B[20];
struct node{ int x,y; }A1[20],B1[20];
int main(){
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			E[i][j]=GETCHAR();
		}
	}
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			T[i][j]=GETCHAR();
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			if(E[i][j]==1 && T[i][j]==0){ cnt1++; A1[cnt1]=(node){i+1,j+1}; }
			if(E[i][j]==0 && T[i][j]==1){ cnt2++; B[cnt2]=cnt2; B1[cnt2]=(node){i+1,j+1}; }
		}
	}
	int Ans=0x7f7f7f7f,tmp=0;
	do{
		tmp=0;
		for(int i=1;i<=cnt1;++i){
			tmp+=Abs(A1[i].x-B1[B[i]].x)+Abs(A1[i].y-B1[B[i]].y);
		}
		if(tmp<Ans) Ans=tmp;
	}while(next_permutation(B+1,B+cnt2+1));
	printf("%d\n",Ans);
	return 0;
}
