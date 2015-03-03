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
struct node{
	int to,next;
}E[15000];
int line[15000],tot=0;
inline void Insert(int x,int y){
	tot++; E[tot].to=y; E[tot].next=line[x]; line[x]=tot;
}
int cnt=0,pre[15000],N,M,R,C;
int hash[60][60]; char map[60][60];
bool flag[15000];
inline bool KM(int x){
	int p=0;
	for(int i=line[x];i!=0;i=E[i].next){
		p=E[i].to;
		if(!flag[p]){
			flag[p]=true;
			if(pre[p]==-1 || KM(pre[p])){
				pre[p]=x; return true;
			}
		}
	}
	return false;
}
int main(){
	freopen("lanzerb.in","r",stdin);
	freopen("lanzerb.out","w",stdout);
	Read(N); Read(M); Read(R); Read(C);
	int dx[]={R,R,C,C}; int dy[]={-C,C,-R,R};
	for(int i=0;i< N;++i) scanf("%s",map[i]);
	cnt=0;
	for(int i=0;i< N;++i){
		for(int j=0;j< M;++j){
			hash[i][j]=cnt++;
		}
	}
	int tmp=N*M,Ans=0;
	for(int i=0;i< N;++i){
		for(int j=0;j< M;++j){
			if(map[i][j]=='x') continue;
			Ans++;
			for(int k=0;k< 4;++k){
				int nx=i+dx[k],ny=j+dy[k];
				if(nx< 0 || ny< 0 || nx>=N || ny>=M || map[nx][ny]=='x') continue;
				Insert(hash[i][j],hash[nx][ny]+tmp);
			}
		}
	}	
	memset(pre,-1,sizeof(pre));
	for(int i=0;i< tmp;++i){
		memset(flag,0,sizeof(flag));
		if(KM(i)) Ans--;
	}
	printf("%d\n",Ans);
	return 0;
}

