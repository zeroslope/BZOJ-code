/*¸ÅÂÊDP*/
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
struct node{
	int to,next;
}E[2010];
int line[1010] = {0} , tot = 0;
int out[1010] = {0} , dis[1010] = {0} , path[1010][1010] = {0};//³ö¶È 
double f[1010][1010]; 
inline void Insert(int x,int y) {
	tot ++ ; E[tot].to = y; E[tot].next = line[x]; line[x] = tot; out[x] ++ ;
}
int n,e,s,t;
inline void init() {
	queue<int>Q;
	for(int k = 1;k <= n;++k) {
		memset(dis,-1,sizeof(dis));
		Q.push(k); path[k][k] = k; dis[k] = 0; 
		int p = 0;
		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int i = line[u];i != 0;i = E[i].next) {
				p = E[i].to;
				if(dis[p] == -1) {
					dis[p] = dis[u] + 1;
					path[p][k] = u;
					Q.push(p);
				} else {
					if(dis[p] == dis[u] + 1 && u < path[p][k])
						path[p][k] = u;
				}
			}
		}
	}
}
inline double DP(int i,int j) {
	if(f[i][j] == -1) {
		double res = 0;
		int x = path[ path[i][j] ][j] ;
		res = DP(x,j) + 1 ;
		if(x != j) {
			for(int k = line[j];k != 0;k = E[k].next) 
				res += DP(x,E[k].to) + 1;
			res /= (double)(out[j] + 1) ;
		}
		f[i][j] = res;
	}
	return f[i][j];
}
int main(){
	Read(n); Read(e); Read(s); Read(t);
	int x = 0,y = 0; 
	for(int i = 1;i <= e;++i) {
		Read(x); Read(y);
		Insert(x,y); Insert(y,x);
	}
	for(int i = 1;i <= n;++i) {
		for(int j = 1;j <= n;++j)
			f[i][j] = -1;
		f[i][i] = 0;
	}
	init();
	printf("%.3lf\n",DP(s,t));
	return 0;
}
