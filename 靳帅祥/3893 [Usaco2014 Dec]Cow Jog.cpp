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
LL N=0,M=0;
LL p[101000],s[101000];
int main(){
	Read(N); Read(M);
	for(int i=1;i<=N;++i){ Read(p[i]); Read(s[i]); }
	int Ans=0;
	for(int i=N;i;--i){
		int now=i; Ans++;
		while(i && (s[i-1]-s[now])*M>=(p[now]-p[i-1])) --i;
	}
	printf("%d\n",Ans);
	return 0;
}

