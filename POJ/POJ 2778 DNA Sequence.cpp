#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std; 
typedef unsigned long long LL;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
struct Matrix {
	LL A[40][40];
	int n;
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
				for(int k = 0;k < n;++k)
					res.A[i][j]+=A[i][k]*b.A[k][j];
		return res;
	}
	Matrix operator *= (const Matrix &b) {
		*this=*this * b;
		return *this;
	}
};
struct TRIE {
	int next[40][26],fail[40]; bool end[40];
	int root , L;
	inline int newnode() {
		for(int i = 0;i < 26;++i) next[L][i] = -1;
		end[L++] = false;
		return L-1;
	}
	inline void init() { L = 0; root = newnode(); }
	inline void insert(char *buf) {
		int len = strlen(buf) , now = root;
		for(int i = 0;i < len;++i){
			if(next[now][buf[i]-'a'] == -1) next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		end[now] = true;
	}
	inline void build() {
		queue<int>Q;
		fail[root] = root;
		for(int i = 0;i < 26;++i) {
			if(next[root][i] == -1) next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		while(!Q.empty()) {
			int now = Q.front(); Q.pop();
			if(end[fail[now]]) end[now] = true;
			for(int i = 0;i < 26;++i) {
				if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	Matrix Get() {
		Matrix res = Matrix(L + 1);
		for(int i = 0;i < L;++i) 
			for(int j = 0;j < 26;++i)
				res.A[i][next[i][j]] ++ ;
		for(int i = 0;i < L+1;++i)
			res.A[i][L] = 1;
		return res;
	}	
}AC;
char buf[10];
inline LL QuickPow(LL a,int k) {
	LL res = 1;
	while(k > 0) {
		if(k & 1) res *= a;
		a *= a; k >>= 1;
	}
	return res;
}
inline Matrix QuickPow(Matrix a ,int k) {
	Matrix res = Matrix(a.n);
	for(int i = 0;i < a.n;++i) res.A[i][i] = 1;
	while(k > 0) {
		if(k & 1) res *= a;
		a *= a; k >>= 1;
	}
	return res;
}
int main(){
	int n , L ;
	while(scanf("%d%d",&n,&L) != EOF) {
		AC.init();
		for(int i = 0;i < n;++i) {
			scanf("%s",buf); AC.insert(buf);
		}
		AC.build();
		Matrix a = AC.Get();
		a = QuickPow(a,L);
		LL res = 0;
		for(int i = 0;i < a.n;++i) res += a.A[0][i];
		res -- ;
		a = Matrix(2);
		a.A[0][0] = 26; a.A[1][0] = a.A[1][1] = 1;
		a = QuickPow(a , L);
		LL ans = a.A[1][0] + a.A[0][0] ;
		ans -- ; ans -= res;
		printf("%lld\n",ans); 
	}
	return 0;
}
/*
* f[n]=1 + 26^1 + 26^2 +...26^n
* f[n]=26*f[n-1]+1
* {f[n] 1} = {f[n-1] 1}[26 0;1 1]
* 数是f[L]-1;
* 此题的L<2^31.矩阵的幂不能是L+1次，否则就超时了
*/
