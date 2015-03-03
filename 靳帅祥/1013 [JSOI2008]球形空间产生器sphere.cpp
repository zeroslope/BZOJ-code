#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
const double eps=1e-6;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N=0;
double f[21],a[21][21];
inline double sqr(double x){ return x*x; }

bool Gauss(){
	int now=1,to; double t;
	for(int i=1;i<=N;i++){
		for(to=now;to<=N;to++) if(fabs(a[to][i])>eps) break;
		if(to> N) continue;
		if(to!=now){
			for(int j=1;j<=N+1;++j)	swap(a[to][j],a[now][j]);
		}
		t=a[now][i];
		for(int j=1;j<=N+1;++j) a[now][j]/=t;
		for(int j=1;j<=N;++j)
			if(j!=now){
				t=a[j][i];
				for(int k=1;k<=N+1;++k) a[j][k]-=t*a[now][k];
			}	
		now++;
	}
	for(int i=now;i<=N;++i)
		if(fabs(a[i][N+1])>eps) return 0;
	return 1;
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;++i) scanf("%lf",&f[i]);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			double t;
			scanf("%lf",&t); 
			a[i][j]=2.0*(t-f[j]);
			a[i][N+1]+=sqr(t)-sqr(f[j]);
		}
	}
	Gauss();
	for(int i=1;i<=N-1;++i)	printf("%.3lf ",a[i][N+1]);
	printf("%.3lf\n",a[N][N+1]);
	return 0;
}
