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
const int maxn = 1010*50;
char str[1010][50];
struct TRIE {
	int next[maxn][128],fail[maxn],end[maxn];
	int L,root;
	inline int newnode() {
		for(int i = 0;i < 128;++i) next[L][i] = -1;
		end[L++] = -1;
		return L-1;
	}
	inline void init() { L = 0; root = newnode(); }
	inline void insert(char *buf,int id) {
		int len = strlen(buf) , now = root;
		for(int i = 0;i < len;++i) {
			if(next[now][buf[i]] == -1) next[now][buf[i]] = newnode();
			now = next[now][buf[i]];
		}
		end[now] = id;
	}
	inline void build(){
		queue<int>Q;
		fail[root] = root;
		for(int i = 0;i < 128;++i){
			if(next[root][i] == -1) next[root][i] = root;
			else{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		} 
		while(!Q.empty()){
			int now = Q.front(); Q.pop();
			for(int i = 0;i < 128;++i){
				if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
				else{
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	int num[1010];
	inline void query(char *buf,int n){
		int len = strlen(buf) , now = root;
		memset(num,0,sizeof(num));
		bool flag = false;
		for(int i = 0;i < len;++i) {
			now = next[now][buf[i]];
			int temp = now;
			while(temp != root) {
				if(end[temp] != -1) num[end[temp]]++;
				temp = fail[temp]; 
			}
		}
		for(int i = 0;i < n;++i)
			if(num[i] > 0) printf("%s: %d\n",str[i],num[i]);
	}
}AC;
char buf[2000010];
int main(){
	int n=0;
	while(scanf("%d",&n) != EOF) {
		AC.init();
		for(int i = 0;i < n;++i) {
			scanf("%s",str[i]);
			AC.insert(str[i],i);
		}
		AC.build();
		scanf("%s",buf);
		AC.query(buf,n);
	}
	return 0;
}
