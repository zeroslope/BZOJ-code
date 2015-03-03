#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXV = 1010;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
bool vis[MAXV];
pair<long long ,int>cost;
pair<long long ,int>
int A=0,B=0,N=0;
int main(){
	Read(A); Read(B); Read(N);
	memset(cost,0x3f,sizeof(cost));
	for(int i=0;i< MAXV;++i) cost[i][i]=makr_pair(0,0);
	long long R_C,R_L;
	for(int i=0;i< N;++i){
		Read(R_C); Read(R_L);
		vector
	}
	return 0;
}