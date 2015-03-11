#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100010;
template<class T>
inline void Read(T& x){
    int f=0; x=0; char ch=getchar();
    while(ch< '0' || ch> '9'){ if(ch=='-'){ f=1; ch=getchar() ;break; } ch=getchar();}
    while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
    if(f==1) x=-x;
}
int mu[MAXN],P[MAXN],flag[MAXN],cnt=0;
inline void Get(){
    mu[1]=1;
    for(int i=2;i<=MAXN;++i){
        if(!flag[i]){ P[++cnt]=i; mu[i]=-1; }
        for(int j=1;j<=cnt;++j){
            int t=P[j]*i; if(t>=MAXN) break;
            flag[t]=true;
            if(i%P[j]==0){ mu[t]=0; break; }
            else mu[t]=-mu[i];
        }
    }
}
LL cal(LL x){
    int s=sqrt(x+0.5); LL res=0;
    for(int i=1;i<=s;++i) res+=mu[i]*(x/(1LL*i*i));
    return res; 
}
int main(){
    Get();
    int T; Read(T);
    while(T--){
        LL k,l,r; Read(k); l=1; r=k<<1;
        while(l<=r){
            LL mid=(l+r)>>1;
            if(cal(mid)>=k) r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",r+1);
    }
    return 0;
}
