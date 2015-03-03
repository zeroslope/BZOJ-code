#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000005;
const LL MOD = 1000000007;
 
char st[MAXN];
int  len,next[MAXN],Next[MAXN],cnt[MAXN];
LL   Ans;
inline void KMP(){
    int t=0;
    for(int i=1;i<=len;++i){
        t=next[i-1];
        while(t!=-1 && st[i]!=st[t+1]) t=next[t];
        next[i]=t+1; cnt[i]=cnt[t+1]+1;
    }
}
inline void ZOO(){
    int t=0;
    for(int i=1;i<=len;++i){
        t=Next[i-1];
        if(t*2+2>i) t=next[t];
        while(t!=-1 && st[i]!=st[t+1]) t=next[t];
        Next[i]=t+1;
    }
}
int main() {
    //freopen("zoo.in","r",stdin);
    //freopen("zoo.out","w",stdout);
    int T;
    scanf("%d\n", &T);
    while (T--){
        gets(st+1); 
        len=strlen(st+1);
        next[0]=Next[0]=-1;
        KMP(); ZOO();
        Ans=1;
        for(int i=1;i<=len;++i){
            (Ans*=(cnt[Next[i]]+1))%=MOD;
        }
        printf("%lld\n",Ans);
    }
    return 0;
}
