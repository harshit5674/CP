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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

const int mxm=1e9+7;
const int mx=2e5+5;
int c;
int n;
int co[mx];
vt<int> adj[mx];
set<pair<int,int>> s1,s2;
map<int,bool> m;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool ok=false,ok1=false;
int d=0;
void check_1(int s,int p){
	for(auto x:adj[s]){
		if(m[x]){
			ok=true;
		}
	}
}

void check_2(int s,int p,int d=0){
	if(d==2){
		if(m[s]){
			ok1=true;
		}
		return;
	}
	for(auto x:adj[s]){
		if(x!=p){
			check_2(x,s,d+1);
		}
	}
}

void dfs(int s,int p,int dd=0){
	if(m[s]&&p!=-1){
		d=min(d,dd);
		return;
	}
	for(auto x:adj[s]){
		if(x!=p){
		dfs(x,s,dd+1);
		}
	}
}

void get_accepted(){
	cin>>n;
	cin>>c;
	m.clear();
	for(int i=0;i<n-1;i++){
		cin>>co[i];
	}
	for(int i=0;i<=n;i++){
		adj[i].clear();
	}
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	m[c]=1;
	ok=false,ok1=false;
	d=INT_MAX;
	for(int i=0;i<n-1;i++){
		m[co[i]]=1;
		if(ok){
			cout<<1<<" ";
			continue;
		}
		check_1(co[i],-1);
		if(ok){
			cout<<1<<" ";
			continue;
		}
		if(ok1){
			cout<<2<<" ";
			continue;
		}
		check_2(co[i],-1);
		if(ok1){
			cout<<2<<" ";
			continue;
		}
		int r=d;
		dfs(co[i],-1);
		d=min(d,r);
		cout<<d<<" ";
	}
	cout<<"\n";
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

