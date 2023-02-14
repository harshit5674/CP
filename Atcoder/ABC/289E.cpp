#include<bits/stdc++.h>

using namespace std;

#define vt vector
#define pb push_back
#define ll long long
#define sz(x) (int)(x).size
#define all(x) (x).begin(),(x).end()
#define allb(x) (x).rbegin(),(x).rend()

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

const int mxm=1e9+7;
const int mx=2e5+5;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int c[2005];
int n;
int m;
vector<int> adj[2005];
vt<int> ans;
int ert=INT_MAX;

void dfs(int s){
	if(s==n){
		ans.push_back(c[s-1]);
		int n=sz(ans);
		bool ok=true;
		for(int i=0;i<n/2;i++){
			if(s[i]==s[n-i-1]){
				ok=false;
			}
		}
		if(ok){
			ert=min(ert,n);
		}
		return;
	}
	ans.pb(c[s-1]);
	for(auto x:adj[s]){
		dfs(x)
}

void get_accepted(){
	cin>>n;
	cin>>m;
	for(int i=0;i<=n;i++){
		adj[i].clear();
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	if(c[0]==c[n-1]){
		cout<<-1<<"\n";
		return;
	}
	dfs(1);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tt;
	cin>>tt;
//	tt=1;
	while(tt--){
		get_accepted();
	}
}

