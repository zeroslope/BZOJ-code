#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 10010;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
struct node{
	double x,y;
	node operator - (const node& b){ return (node){x-b.x,y-b.y}; }
}P[MAXN],ch[MAXN];
inline bool cmp(const node& a,const node& b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x; 
}
inline double Cross(node a,node b){ return (a.x*b.y)-(a.y*b.x); }
inline double Dist(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
inline int ConvexHull(node* p,int n,node* ch){
	sort(p,p+n,cmp);
	int m=0;
	for(int i=0;i< n;++i){
		while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	int k=m;
	for(int i=n-2;i>=0;--i){
		while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}
	if(n>1) m--;
	return m;
}
int N=0;
int main(){
	freopen("fc.in","r",stdin);
	freopen("fc.out","w",stdout);
	scanf("%d",&N);
	for(int i=0;i< N;++i) scanf("%lf%lf",&P[i].x,&P[i].y);
	int m=ConvexHull(P,N,ch);
	double Ans=0.0F;
	for(int i=0;i< m;++i){
		Ans+=Dist(ch[i],ch[i+1]);
	}
	printf("%.2lf",Ans);
	return 0;
}
