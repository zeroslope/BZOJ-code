#include <cstdio>
#include <cmath>
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
LL  Ans=0;
int N,M,SIZE=316,cntb=1;
//块 原数组 块大小 每个元素的位置
int Blo[320][320],num[100010]={0},siz[320]={0},pos[100010]={0};
int tmp[100010],bel[100010];//归并 属于哪个块

//归并排序
inline void MERGE(int l,int mid,int r){
	static int res[100010];
	int i=l,j=mid+1,p=l;
	while(i<=mid && j<=r){
		if(tmp[i]>tmp[j]) res[p++]=tmp[j++],Ans+=(mid-i+1);
		else res[p++]=tmp[i++];
	}
	while(i<=mid) res[p++]=tmp[i++];
	while(j<=r  ) res[p++]=tmp[j++];
	for(i=l;i<=r;++i) tmp[i]=res[i];
}
inline void MERGE_SORT(int l,int r){
	if(l< r){
		int mid=(l+r)>>1;
		MERGE_SORT(l,mid);
		MERGE_SORT(mid+1,r);
		MERGE(l,mid,r);
	}
}
inline int lower_bound(int *num,int siz,int x){
	int l=1,r=siz,mid,ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(num[mid]<=x) ans=mid,l=mid+1;
		else r=mid-1; 
	}
	return ans;
}
inline int lower(int blc,int x){
	return lower_bound(Blo[blc],siz[blc],x);
}
inline int Upper(int blc,int x){
	return siz[blc]-lower_bound(Blo[blc],siz[blc],x);
}
inline int CALC(int x){
	int res=0,k=bel[pos[x]];
	for(int i=1;i< k;++i) res+=Upper(i,x);
	for(int i=k+1;i<=cntb;++i){ res+=lower(i,x); }
	for(int i=1;i<=siz[k];++i){
		if(Blo[k][i]<x && pos[Blo[k][i]]>pos[x]) res++;
		if(Blo[k][i]>x && pos[Blo[k][i]]<pos[x]) res++;
	}
	return res;
}
inline void DELETE(int blc,int x){
	int t=lower_bound(Blo[blc],siz[blc],x);
	while(t<siz[blc]){ Blo[blc][t]=Blo[blc][t+1]; t++; }
	siz[blc]--;
}
int main(){
	Read(N); Read(M);
	for(int i=1;i<=N;++i){
		Read(num[i]); pos[num[i]]=i; tmp[i]=num[i];//记录位置 用于判断逆序对
	}
	int cnt=sqrt(N+0.5);
	for(int i=1;i<=N;++i){
		Blo[cntb][++siz[cntb]]=num[i];
		bel[i]=cntb; if(siz[cntb]>=cnt) cntb++;
	}
	for(int i=1;i<=cntb;++i) sort(Blo[i]+1,Blo[i]+siz[i]+1);
	MERGE_SORT(1,N); int d=0;
	while(M--){
		printf("%lld\n",Ans);
		Read(d);
		Ans-=CALC(d);
		DELETE(bel[pos[d]],d);
	}
	return 0;
}
