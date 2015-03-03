#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=200005;
typedef long long LL;
template<class T>inline void Read(T& x){
    x=0; bool flag=0; char ch=getchar();
    while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
    while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
    if(flag) x=-x;
}
int N=0;
struct Point{
    int x, y;
    Point operator - (const Point& b) const {
		Point res; res.x=x-b.x; res.y=y-b.y;
		return res;
	}
}p[200],ch[200];
inline double Cross(Point a, Point b){
    return (a.x*b.y)-(a.y*b.x);
}
// 小於。依座標大小排序，先排 x 再排 y。
inline bool cmp(const Point& a,const Point& b){
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
inline int ConvexHull(Point* p,int n,Point* ch){
    sort(p,p+n,cmp);
    int m=0;
    for(int i=0;i< n;++i){
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0) m--;
        ch[m++]=p[i];  
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}
int main(){
	int T=0;
	Read(T);
	while(T--){
    	Read(N);
	    for(int i=0;i< N;++i) scanf("%d%d",&p[i].x,&p[i].y); 
	    int m=ConvexHull(p,N,ch);
	    sort(ch,ch+m,cmp);
	    for(int i=0;i< m;++i){
	        printf("%d %d\n",ch[i].x,ch[i].y);
	    }
	}
    return 0;
}   
