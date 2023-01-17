#include<bits/stdc++.h>

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

const int mxm=1e9+7;
const int mx=1e5+5;

vector<int> adj[mx];
bool visited[mx];
bool color[mx];
int parent[mx];
int cyend=-1;
int cstart=-1;

bool dfs(int s,int p){
	visited[s]=1;
	for(auto x:adj[s]){
		if(x==p){
			continue;
		}
		if(visited[x]){
			cyend=s;
			cstart=x;
			return true;
		}
		parent[x]=s;
		if(dfs(x,parent[x])){
			return true;
		}
	}
	return false;
}
void get_accepted(){
	int n;
	cin>>n;
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]&&dfs(i,parent[i])){
			break;
		}
	}
	vector<int> ans;
	if(cstart==-1){
		cout<<"IMPOSSIBLE";
		return;
	}
	else{
		ans.push_back(cstart);
		for(int i=cyend;i!=cstart;i=parent[i]){
			ans.push_back(i);
		}
		ans.push_back(cstart);
	}
	cout<<ans.size();
	cout<<"\n";
	for(auto x:ans){
		cout<<x<<" ";
	}
}

int main(){
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		get_accepted();
	}
}

