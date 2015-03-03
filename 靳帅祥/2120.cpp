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
int N=0,M=0;
int col[15000],mark[15000],used[1000010];
int main(){
	freopen("nt2011_color.in","r",stdin);
	freopen("nt2011_color.out","w",stdout);
	Read(N); Read(M);
	int a=0,b=0,tim=0,cnt=0,Ans=0;
	for(int i=1;i<=N;++i){
		Read(a);
		if(!used[a]) used[a]=++tim;
		col[i]=used[a];
	}
	while(M--){
		char ch=getchar(); while(ch!='Q' && ch!='R') ch=getchar();
		if(ch=='Q'){
			Ans=0; cnt++; Read(a); Read(b);
			for(int i=a;i<=b;++i){
				if(mark[col[i]]!=cnt){ mark[col[i]]=cnt; Ans++; }
			} printf("%d\n",Ans);
		}else{
			Read(a); Read(b);
			if(!used[b]) used[b]=++tim;
			col[a]=used[b];
		}
	}
	return 0;
}
