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
int dis1[mx];
int parent[mx]={0};

void get_accepted(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<int> q;
	q.push(1);
	dis1[1]=0;
	while(!q.empty()){
		int s=q.front();
		q.pop();
		visited[s]=1;
		for(auto x:adj[s]){
			if(visited[x])continue;
			q.push(x);
			dis1[x]=dis1[s]+1;
			visited[x]=1;
			parent[x]=s;
		}
	}
	if(visited[n]==0){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	else{
		cout<<dis1[n]+1<<"\n";
		vector<int> ans;
		for(int i=n;i!=1;i=parent[i]){
			ans.push_back(i);
		}
		ans.push_back(1);
		reverse(ans.begin(),ans.end());
		for(auto x:ans){
			cout<<x<<" ";
		}
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

