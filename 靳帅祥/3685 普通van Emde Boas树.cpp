#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1000010 ;
char ch[20000000],*ptr=ch;
inline int GETCHAR(){ return *ptr++; }
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=GETCHAR();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=GETCHAR(); break; } ch=GETCHAR();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=GETCHAR(); }
	if(flag) x=-x;
}

int n,k;
int m1=1,T[MAXN*3]={0};
#define L(x)(x<<1)
#define R(x)(x<<1|1)
inline int find(int x){
	x+=m1;
	if(!T[x]) return -1;
	else return 1;
}
inline void Insert(int x,int v){
	x+=m1; T[x]+=v;
	for(x>>=1;x;x>>=1) T[x]=T[L(x)] + T[R(x)];
}
inline int Get_Min(int o){
	if(!T[o]) return -1;
	while(o<=m1){
		if(T[L(o)]) o=L(o);
		else o=R(o);
	}
	return o-m1-1;
}
inline int Get_Max(int o){
	if(!T[o]) return -1;
	while(o<=m1){
		if(T[R(o)]) o=R(o);
		else o=L(o);
	}
	return o-m1-1;
}
inline int Get_Pre(int o){
	o+=m1;
	while(1){
		if(o==1) return -1;
		if( o&1 && T[o^1]) return Get_Max(o^1);
		o>>=1; 
	}
	return o-m1-1;
}
inline int Get_Suc(int o){
	o+=m1;
	while(1){
		if(o==1) return -1;
		if(!(o&1) && T[o^1]) return Get_Min(o^1);
		o>>=1; 
	}
	return o-m1-1;
}
int main(){
	//freopen("1.in","r",stdin);
	fread(ptr,1,20000000,stdin);
	Read(n); Read(k);
	for(m1=1;m1<=n+2;m1<<=1);
	int op=0,x=0;
	while(k--){
		Read(op); 
		if(op==1){
			Read(x); ++x;
			if(find(x)==-1) Insert(x, 1);
		}
		if(op==2){
			Read(x); ++x;
			if(find(x)== 1) Insert(x,-1); 
		}
		if(op==3){
			printf("%d\n",Get_Min(1));
		}
		if(op==4){
			printf("%d\n",Get_Max(1));
		}
		if(op==5){
			Read(x); ++x;
			printf("%d\n",Get_Pre(x));
		}
		if(op==6){
			Read(x); ++x;
			printf("%d\n",Get_Suc(x));
		}
		if(op==7){
			Read(x); ++x;
			printf("%d\n",find(x));
		}
	}
	return 0;
}
