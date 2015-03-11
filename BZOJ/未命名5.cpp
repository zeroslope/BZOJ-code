#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 505
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
long long n,m;
long long f[N][N],x[N],y[N];
int main()
{
    //freopen("test.in","r",stdin);
    cin>>n>>m;
    int i,j,k;
    for(i=1;i<=n;i++)cin>>x[i]>>y[i];
    memset(f,0x3f,sizeof f);
    f[1][0]=0;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<i-1&&j<=m;j++)
        {
            for(k=i-1;i-k-1<=j&&k;k--)
            {
                f[i][j]=min(f[i][j],f[k][j-(i-k-1)]+abs(x[i]-x[k])+abs(y[i]-y[k]));
            }
        }
    }
    long long ans=INF;
    for(i=0;i<=m;i++)ans=min(ans,f[n][m]);
        cout<<ans<<endl;
    return 0;
}
