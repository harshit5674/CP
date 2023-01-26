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
int n,m;

bool f(int mid,vt<vt<int>> &a,vt<vt<int>> &dp){
	int tm[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=0;
			tm[i][j]=(a[i][j]>=mid);
		}
	}
	for(int i=0;i<m;i++){
		if(tm[0][i]){
			dp[0][i]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(tm[i][0]){
			dp[i][0]=1;
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(tm[i][j]){
				dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
			}
			ans=max(ans,dp[i][j]);
		}
	}
	return ans>=mid;
}
void get_accepted(){
	cin>>n>>m;
	vt<vt<int>> a(n,vt<int>(m,0));
	vt<vt<int>> dp(n,vt<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int lo=1,hi=1000000;
	debug(lo,hi);
	while(lo<hi){
		int mid=lo+(hi-lo+1)/2;
		if(f(mid,a,dp)){
			lo=mid;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<lo<<"\n";
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

