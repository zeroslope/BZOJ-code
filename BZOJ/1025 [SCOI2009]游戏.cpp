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
LL  Ans=0,f[1010][1010];
int N=0;
bool flag[1010]; 
int Prime[1010],tot=0;
inline void GetPrime(){
	for(int i=2;i<=1000;++i){
		if(!flag[i]) Prime[++tot]=i;
		for(int j=1;j<=tot && i*Prime[j]<=1000;++j){
			flag[i*Prime[j]]=1;
			if(i%Prime[j]==0) break;
		}
	}
}

int main(){
	Read(N);
	GetPrime();
	f[0][0]=1;
	for(int i=1;i<=tot;++i){ 
		for(int j=0;j<=N;++j) f[i][j]=f[i-1][j];
		for(int j=Prime[i];j<=N;j*=Prime[i]){
			for(int k=0;k<=N-j;++k){
				f[i][k+j]+=f[i-1][k];
			}	
		}
	}
	for(int i=0;i<=N;++i) Ans+=f[tot][i];
	printf("%lld\n",Ans);
	return 0;
}
