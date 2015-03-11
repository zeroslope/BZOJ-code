#include <cstdio>
using namespace std;
typedef long long LL;
template<class T>
inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int A[1010]={0};
inline int Abs(int x){ if(x<0) return -x; return x;}
int main(){
	int T; Read(T);
	while(T--){
		int N=0; Read(N);
		for(int i=1;i<=N;++i) Read(A[i]);
		if(Abs(A[1]-A[N])<=1) printf("0\n");
		else printf("1\n");
	}
	return 0;
}

