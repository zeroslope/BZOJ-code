#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define Maxn 100010
#define Maxp 910
#define LD double
//#define pi 3.1415926535897932384626433832795
#define eps 1e-9

using namespace std;

int n,m,belong[Maxn],blcsiz;

struct node{LD x,y;};

struct ASK{
	int k;
	LD x,y;
}Ask[Maxn]={0};

struct Blc{
	node Snode;
	LD Ang;
}Blc[Maxp]={0};

void Rot(node &o,LD Ang){
	LD xr,yr;
	xr=sin(Ang)*o.x+cos(Ang)*o.y;
	yr=cos(Ang)*o.x-sin(Ang)*o.y;
	o.x=yr; o.y=xr;
}

LD Dec(LD x){
	if(x<=eps&&x>=-eps) return 0.00;
	else return x;
}

void Solve(int L,int R){
	node res={0};
	int l=belong[L],r=belong[R];
	for(int i=L;i<=min(l*blcsiz,R);i++){
		if(Ask[i].k==1) res.x+=Ask[i].x,res.y+=Ask[i].y;
		else if(Ask[i].k==2) Rot(res,Ask[i].x);
	}
	for(int i=l+1;i<r;i++){
		Rot(res,Blc[i].Ang);
		res.x+=Blc[i].Snode.x;
		res.y+=Blc[i].Snode.y;
	}
	if(l!=r){
		for(int i=(r-1)*blcsiz+1;i<=R;i++){
			if(Ask[i].k==1) res.x+=Ask[i].x,res.y+=Ask[i].y;
			else if(Ask[i].k==2) Rot(res,Ask[i].x);
		}
	}
	printf("%.9lf %.9lf\n",Dec(res.x),Dec(res.y));
}

void Init(){
	scanf("%d%d",&n,&m); blcsiz=(int)sqrt(n+0.5);
	for(int i=1;i<=n;i++){
        belong[i]=(i-1)/blcsiz+1;
		scanf("%d",&Ask[i].k);
		if(Ask[i].k==1) scanf("%lf%lf",&Ask[i].x,&Ask[i].y);
		else if(Ask[i].k==2) scanf("%lf",&Ask[i].x);
	}
}
void Solve1(){
	for(int i=1;i<=n;i++){
		if(Ask[i].k==2){
			Blc[belong[i]].Ang+=Ask[i].x;
			Rot(Blc[belong[i]].Snode,Ask[i].x);
			continue;
		}
		Blc[belong[i]].Snode.x+=Ask[i].x;
		Blc[belong[i]].Snode.y+=Ask[i].y;
	}
	
	for(int i=1;i<=n/blcsiz;++i){
		printf("%lf %lf %lf\n",Blc[i].Snode.x,Blc[i].Snode.y,Blc[i].Ang);
	}
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		if(l>r) swap(l,r);
		if(l>n&&r>n){
			puts("0.0000000");
			continue;
		}
		r=min(r,n);// l=min(l,n);
		Solve(l,r);
	}
}

int main(){
	freopen("point.in","r",stdin);
	//freopen("point.out","w",stdout);
	Init();
	//Solve0();
	Solve1();
	return 0;
}
