#include <cstdio>
#include <queue>
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
const int MOD = 20090717;
int n,m,k;
int dp[30][110][1<<10],num[5000];
struct TRIE {
	int next[110][26],fail[110],end[110];
	int root , L ;
	int newnode() {
		for(int i = 0;i < 26; ++i) next[L][i] = -1;
		end[L++] = 0;
		return L-1;
	}
	void init() { L = 0; root = newnode();}
	void insert(char *buf,int id) {
		int len = strlen(buf) , now = root;
		for(int i = 0;i < len;++i) {
			if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		end[now] |= (1<<id) ;
	}
	void build() {
		queue<int>Q;
		fail[root] = root ;
		for(int i = 0;i < 26;++i) {
			if(next[root][i] == -1) next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		while(!Q.empty()) {
			int now = Q.front(); Q.pop();
			end[now] |= end[fail[now]] ;
			for(int i = 0;i < 26;++i){
				if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	int solve() {
		for(int i = 0;i <= n;++i) 
			for(int j = 0;j < L;++j)
				for(int p = 0;p < (1<<m);++p)
					dp[i][j][p] = 0;
		dp[0][0][0] = 1;
		for(int i = 0;i <= n;++i) 
			for(int j = 0;j < L;++j)
				for(int p = 0;p < (1<<m);++p)
					if(dp[i][j][p] > 0) {
						for(int x = 0;x < 26;++x) {
							int ni = i+1 , nj = next[j][x] , np = p | end[nj];
							( dp[ni][nj][np] += dp[i][j][p] ) %= MOD; 
						}
					}
		int ans = 0;
		for(int  p = 0;p < (1<<m);++p) {
			if(num[p] < k) continue;
			for(int i = 0;i < L;++i) {
				( ans += dp[n][i][p] ) %= MOD;
			}
		}
		return ans;
	}
}AC;
char buf[20] ;
int main(){
	for(int i = 0;i < (1<<10);++i) {
		num[i] = 0;
		for(int j = 0;j < 10;++j) {
			if(i & (1<<j)) num[i] ++; 
		}
	}
	while(scanf("%d%d%d",&n,&m,&k) == 3) {
		if(n==0 && m==0 && k==0) break;
		AC.init();
		for(int i = 0;i < m;++i) {
			scanf("%s",buf);
			AC.insert(buf,i);
		}
		AC.build();
		printf("%d\n",AC.solve());
	}
	return 0;
}

