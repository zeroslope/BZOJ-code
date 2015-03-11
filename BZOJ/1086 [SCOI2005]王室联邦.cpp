#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=300010;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N=0,B=0;
vector<int>Map[MAXN];
int tot=0,cnt=0,Belong[MAXN]={0};
int DFN[MAXN]={0},siz[MAXN]={0},Root[MAXN]={0};
inline void DFS(int x,int fa){
	DFN[++tot]=x;
	for(int i=0;i< Map[x].size();++i){
		if(Map[x][i]!=fa){
			DFS(Map[x][i],x); siz[x]+=siz[Map[x][i]];
			if(siz[x]>=B){
				Root[++cnt]=x;
				for(;tot>0 && DFN[tot]!=x;tot--) Belong[DFN[tot]]=cnt;
				siz[x]=0;
			}
		}
	}
	siz[x]++;
}
int main(){
	Read(N); Read(B);
	int x=0,y=0;
	for(int i=1;i< N;++i){
		Read(x); Read(y);
		Map[x].push_back(y); Map[y].push_back(x);
	}
	if(N< B) printf("0\n");
	else{
		DFS(1,1);
		while(tot>0) Belong[DFN[tot]]=cnt,tot--;
		printf("%d\n",cnt);
		for(int i=1;i<=N;++i) printf("%d ",Belong[i]); printf("\n");
		for(int i=1;i<=cnt;++i) printf("%d ",Root[i]); printf("\n");
	}
	return 0;
}
