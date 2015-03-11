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
const int MAXN = 500010;
struct TRIE {
	int next[MAXN][26],fail[MAXN],end[MAXN];
	int L , root;
	int newnode() {
		for(int i = 0;i < 26;++i) next[L][i] = -1;
		end[L++] = 0;
		return L-1;
	}
	void init() { L = 0; root = newnode(); }
	void insert(char *buf) {
		int len = strlen(buf) , now = root;
		for(int i = 0;i < len;++i) {
			if(next[now][buf[i]-'a'] == -1) 
				next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		end[now]++;
	}
	void build() {
		queue<int>Q;
		for(int i = 0;i < 26;++i) {
			if(next[root][i] == -1) next[root][i] = root;
			else{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}	
		}
		while(!Q.empty()) {
			int now = Q.front(); Q.pop();
			for(int i = 0;i < 26;++i) {
				if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
				else{
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	int query(char *buf) {
		int len = strlen(buf),now = root,res = 0;
		for(int i = 0;i < len;++i) {
			now = next[now][buf[i]-'a'];
			int temp = now;
			while(temp != root){
				res += end[temp];
				end[temp] = 0;
				temp = fail[temp]; 
			}
		}
		return res;
	}
}AC;
char buf[1000010];
int main(){
	int T,n;
	Read(T);
	while(T--){
		Read(n);
		AC.init();
		for(int i = 0;i < n;++i){
			scanf("%s",buf);
			AC.insert(buf);
		}
		AC.build();
		scanf("%s",buf);
		printf("%d\n",AC.query(buf));
	}
	return 0;
}
