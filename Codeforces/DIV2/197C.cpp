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

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dp[55];
int n;
string s;
bool ok=false;
vt<int> w;
vt<int> ans1,ans2;
int m;
void dfs(int x,int y,int i,int p){
					if(ok){
						return;
					}
	if(i==m){
		if(ok){
			return;
		}
		ans2=ans1;
		ok=true;
		return;
	}
	if(i%2==0){
		for(auto r:w){
			if(r!=p){
				if(x+r>y){
					ans1.pb(r);
					dfs(x+r,y,i+1,r);
					if(ok){
						return;
					}
					ans1.pop_back();
				}
			}
		}
	}
	else{
		for(auto r:w){
			if(r!=p){
				if(y+r>x){
					ans1.pb(r);
					dfs(x,y+r,i+1,r);
					if(ok){
						return;
					}
					ans1.pop_back();
				}
			}
		}

					if(ok){
						return;
					}
	}
}

void get_accepted(){
	cin>>s;
	cin>>m;
	int i=0;
	for(auto x:s){
		if(x=='1'){
			w.pb(i+1);
		}
		i++;
	}
	dfs(0,0,0,0);
	if(ok){
		cout<<"YES\n";
		for(auto x:ans2){
			cout<<x<<" ";
		}
	}
	else{
		cout<<"NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		get_accepted();
	}
}


