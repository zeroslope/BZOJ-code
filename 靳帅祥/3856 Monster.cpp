#include <cstdio>
typedef long long LL;
template<class T>inline void Read(T& x){
x=0; bool flag=0; char ch=getchar();
while(ch> '9'||ch< '0'){ if(ch=='-'){flag=1;ch=getchar();break;}ch=getchar();}
while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}if(flag)x=-x;
}
int main(){
	int T=0;LL H,A,B,K;
	while(1){
		T++;Read(H);Read(A);Read(B);Read(K); 
		if(H+A+B+K==0) break; 
		if(A>=H||H-K*(A-B)<=B||K*(A-B)-B>0)printf("Case #%d: YES\n",T);else printf("Case #%d: NO\n",T);
	}
	return 0;
}

