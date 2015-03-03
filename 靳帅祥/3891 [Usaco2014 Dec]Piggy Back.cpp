#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=40010;
template<class T>
inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
struct node{
	int to,next;
}E[MAXN<<1];
int line[MAXN],tot=0;
int B=0,e=0,P=0,N=0,M=0;
inline void Insert(int x,int y){
	tot++; E[tot].to=y; E[tot].next=line[x]; line[x]=tot;
}
int Dis1[MAXN],Dis2[MAXN],Dis3[MAXN];
queue<int>Q; bool flag[MAXN];
inline void SPFA1(){
	memset(Dis1,0x3f,sizeof(Dis1));
	Q.push(1); Dis1[1]=0; flag[1]=true;
	while(!Q.empty()){
		int t=Q.front(); Q.pop(); flag[t]=false;
		for(int i=line[t];i!=0;i=E[i].next){
			int p=E[i].to;
			if(Dis1[p]>Dis1[t]+B){
				Dis1[p]=Dis1[t]+B;
				if(!flag[p]){
					flag[p]=true; Q.push(p);
				}
			}
		}
	}
} 
inline void SPFA2(){
	memset(Dis2,0x3f,sizeof(Dis2));
	Q.push(2); Dis2[2]=0; flag[2]=true;
	while(!Q.empty()){
		int t=Q.front(); Q.pop(); flag[t]=false;
		for(int i=line[t];i!=0;i=E[i].next){
			int p=E[i].to;
			if(Dis2[p]>Dis2[t]+e){
				Dis2[p]=Dis2[t]+e;
				if(!flag[p]){
					flag[p]=true; Q.push(p);
				}
			}
		}
	}
} 
inline void SPFA3(){
	memset(Dis3,0x3f,sizeof(Dis3));
	Q.push(N); Dis3[N]=0; flag[N]=true;
	while(!Q.empty()){
		int t=Q.front(); Q.pop(); flag[t]=false;
		for(int i=line[t];i!=0;i=E[i].next){
			int p=E[i].to;
			if(Dis3[p]>Dis3[t]+P){
				Dis3[p]=Dis3[t]+P;
				if(!flag[p]){
					flag[p]=true; Q.push(p);
				}
			}
		}
	}
}

int main(){
	Read(B); Read(e); Read(P); Read(N); Read(M);
	int x=0,y=0;
	for(int i=1;i<=M;++i){
		Read(x); Read(y);
		Insert(x,y); Insert(y,x);
	}
	SPFA1(); SPFA2(); SPFA3();
	int Ans=0x7f7f7f7f; 
	for(int i=1;i<=N;++i){
		if(Ans>Dis1[i]+Dis2[i]+Dis3[i]) Ans=Dis1[i]+Dis2[i]+Dis3[i];
	}
	printf("%d\n",Ans);
	return 0;
}
