#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
const double eps=1e-6;
template<class T>inline void Read(T& x){
	x=0; bool flag=0; char ch=getchar();
	while(ch> '9' || ch< '0'){ if(ch=='-'){ flag=1; ch=getchar(); break; } ch=getchar();}
	while(ch>='0' && ch<='9'){ x=x*10+ch-48; ch=getchar(); }
	if(flag) x=-x;
}
int N=0;
set<int> seen,active;
std::vector<pair<int,int> > events;
int main(){
	Read(N);
	int x,y,r;
	for(int i=0;i< N;++i){
		Read(x); Read(y); Read(r);
		x*=-r;
		events.push_back(make_pair(x-r,y));
		events.push_back(make_pair(x, -y));
	}
	sort(events.begin(),events.end());
	for(int i=0;i< events.size(); ){
		int j=0;
		for(j=i;j< events.size() && events[i].first==events[j].first;j++){
			y=events[j].second;
			if(y>0) active.insert(y);
			else active.erase(-y);
		}
		if(!active.empty()){
			seen.insert(*active.begin());
		}
		i=j;
	}
	printf("%d\n",seen.size());
	return 0;
}
