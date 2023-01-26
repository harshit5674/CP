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
set<int> s;

void get_accepted(){
	cin>>n;
	int sum=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=2;
	for(int i=4;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-3]+1;
	}
	cout<<dp[n];
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


