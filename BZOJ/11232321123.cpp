#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm> 
using namespace std;
#define N 2008

int ans1,ans2,n,m,f[N][N],s[N],w[N],top;
bool map[N][N];

void build()
{
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        {   
            int a; scanf("%d",&a);
            if ((i & 1) == (j & 1) && a || (i & 1) != (j & 1) && !a) map[i][j] = 1;//& 优先级低于 ==!! 
            else map[i][j] = 0;
        }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (map[i][j]) f[i][j] = f[i][j-1] + 1;
            else f[i][j] = 0;
}

void rebuild()
{
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
//            map[i][j] = ~map[i][j]; 不能按位取反！！因为第一位之后的也会取反！！
            map[i][j] = !map[i][j];  
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (map[i][j]) f[i][j] = f[i][j-1] + 1;
            else f[i][j] = 0;
}

inline int sqr(int a)
    {return (a*a);}
    
void work()
{
    for (int j = 1;j <= m;j++)
    {
        top = 0;
        for (int i = 1;i <= n + 1;i++)
        {
            int minw = i;
            while (top && s[top] >= f[i][j])
            {
                ans1 = max(ans1,s[top] * (i - w[top]));
                ans2 = max(ans2,sqr(min(s[top],i-w[top])));
                minw = w[top];
                top--;
            }
            s[++top] = f[i][j]; w[top] = minw;
        }
    }
}

void makeline()
{for (int i = 1;i <= m;i++) printf("--");printf("\n");}
int main(){
    build();
    work();
    rebuild();
    work();
    printf("%d\n%d\n",ans2,ans1);
    return 0;
}
