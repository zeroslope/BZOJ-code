#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std; 
typedef long long LL;
const int INF = 0x3f3f3f3f;
struct TRIE {
	int next[1010][4],fail[1010]; bool end[1010];
	int root , L;
	int newnode() {
		for(int i = 0;i < 4;++i) next[L][i] = -1;
		end[L++] = false;
		return L-1;
	}
	inline void init() { L = 0; root = newnode(); }
	inline int turn(char ch){
		switch(ch){
			case 'A': return 0; break;
			case 'C': return 1; break;
			case 'G': return 2; break;
			case 'T': return 3; break;
		}
	}
	inline void insert(char *buf) {
		int len = strlen(buf) , now = root ,id = 0 ;
		for(int i = 0;i < len;++i){
			id = turn(buf[i]);
			if(next[now][id] == -1) next[now][id] = newnode();
			now = next[now][id];
		}
		end[now] = true;
	}
	inline void build() {
		queue<int>Q;
		for(int i = 0;i < 4;++i) {
			if(next[root][i] == -1) next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		while(!Q.empty()) {
			int now = Q.front(); Q.pop();
			if(end[fail[now]] == true) end[now] = true;
			for(int i = 0;i < 4;++i) {
				if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	int dp[1010][1010] ;
	int solve(char *buf) {
		int len = strlen(buf);
		for(int i = 0;i <= len;++i)
			for(int j = 0;j < L;++j)
				dp[i][j] = INF;
		dp[0][root] = 0;
		for(int i = 0;i < len;++i)
			for(int j = 0;j < L;++j)
				if(dp[i][j] < INF) {
					for(int k = 0;k < 4;++k) {
						int down = next[j][k];
						if(end[down]) continue; //能够构成一个串
						int tmp = 0;
						if(turn(buf[i]) == k) tmp = dp[i][j];
						else tmp = dp[i][j] + 1;
						dp[i+1][down] = min(dp[i+1][down],tmp);  
					}
				}
		int res = INF;
		for(int j = 0;j < L;++j)
			res = min(res,dp[len][j]);
		if(res == INF) res = -1;
		return res;
	}
}AC;
char buf[1010];
int main(){
	int n , js = 0 ;
	while(scanf("%d",&n) == 1 && n) {
		js ++ ;
		AC.init();
		for(int i = 0;i < n;++i) {
			scanf("%s",buf); AC.insert(buf);
		}
		AC.build();
		scanf("%s",buf);
		printf("Case %d: %d\n",js,AC.solve(buf));
	}
	return 0;
}
