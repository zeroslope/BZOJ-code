#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=200005,P=16777215;
typedef long long LL;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N=0,Res=0,A[MAXN]={0};
LL  l[MAXN],r[MAXN],T[MAXN];
inline void Insert(int x,int v){
	for(int i=x;i<=N;i+=i&(-i)) T[i]+=v;
}
inline LL  Query(int x){
	LL Res=0;
	for(int i=x;i;i-=i&(-i)) Res+=T[i];
	return Res;
}
inline void Init(){
	for(int i=1;i<=N;++i){
		l[i]=Query(A[i]); r[i]=A[i]-l[i]-1;
		Insert(A[i],1);
	}
}

inline int cal1(){//1x2x
	memset(T,0,sizeof(T));
	LL res=0;
	for(int i=1;i<=N;++i){
		res=(res+(l[i]*(i-1)-Query(A[i])-l[i]*(l[i]-1)/2)*(N-r[i]-i))&P;
		Insert(A[i],i);
	}
	return res;
}
inline int cal2(){
	memset(T,0,sizeof(T));
    LL res=0;
	for(int i=N;i;i--)
	{
		res=(res+(Query(A[i])-r[i]*(r[i]+1)/2)*(N-r[i]-i))&P;
		Insert(A[i],A[i]);
	}
	return res;
}
inline int cal3(){
	memset(T,0,sizeof(T));
	LL res=0;
	for(int i=1;i<=N;i++){
		res=(res+Query(A[i])*(N-i-r[i]))&P;
		Insert(A[i],l[i]);
	}
	return res;
}
inline int cal4(){
	LL res=0;
	for(int i=1;i<=N;i++){
		LL T1=N-i-r[i];
		if(T1>=3) res=(res+T1*(T1-1)*(T1-2)/6)&P;
	}
	return res;
}
int main(){
	Read(N);
	for(int i=1;i<=N;++i) Read(A[i]);
	Init();
	printf("%d",(cal1()+cal2()+cal3()-cal4())&P);
	return 0;
}

