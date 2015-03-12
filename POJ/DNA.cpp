#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std; 
typedef long long LL;
const int MOD = 100000;
struct Matrix {
	int A[110][110] , n;
	Matrix() {} 
	Matrix(int m) {
		n = m;
		for(int i = 0;i < n;++i)
			for(int j = 0;j < n;++j)
				A[i][j] = 0;
	}
	Matrix operator * (const Matrix &b) const {
		Matrix res = Matrix(n);
		for(int i = 0;i < n;++i)
			for(int j = 0;j < n;++j)
				for(int k = 0;k < n;++k) {
					int tmp = (LL)A[i][k]*b.A[k][j] % MOD;
					(res.A[i][j] += tmp ) %= MOD;
				}
		return res;
	}
};
struct TRIE {
	int next[110][4],fail[110]; bool end[110];
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
	Matrix Get() {
		Matrix res = Matrix(L);
		for(int i = 0;i < L;++i) 
			for(int j = 0;j < 4;++j)
				if(end[next[i][j]] == false)
					res.A[i][next[i][j]] ++ ;
		return res;
	}	
}AC;
char buf[20];
inline Matrix QuickPow(Matrix a ,int k) {
	Matrix res = Matrix(a.n);
	for(int i = 0;i < a.n;++i) res.A[i][i] = 1;
	while(k) {
		if(k & 1) res = res * a;
		a = a * a; k >>= 1;
	}
	return res;
}
int main(){
	int n , m ;
	while(scanf("%d%d",&n,&m) != EOF) {
		AC.init();
		for(int i = 0;i < n;++i) {
			scanf("%s",buf); AC.insert(buf);
		}
		AC.build();
		Matrix a = AC.Get();
		a = QuickPow(a,m);
		int res = 0;
		for(int i = 0;i < a.n;++i) res = ( res + a.A[0][i] ) % MOD;
		printf("%d\n",res); 
	}
	return 0;
}
