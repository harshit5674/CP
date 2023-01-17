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
const int mx=2e5+5;
long long dp[5005][5005][2];

long long solve(int l,int r,int t,long long a[],long long pref[]){
	if(l>r){
		return 0;
	}
	if(dp[l][r][t]!=-1){
		return dp[l][r][t];
	}
	if(l==r){
		return a[l];
	}
	return dp[l][r][t]=max(pref[r+1]-pref[l+1]-solve(l+1,r,1-t,a,pref)+a[l],pref[r]-pref[l]-solve(l,r-1,1-t,a,pref)+a[r]);
}

void get_accepted(){
	int n;
	cin>>n;
	long long a[n];;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long pref[n+1]={0};
	for(int i=1;i<=n;i++){
		pref[i]=pref[i-1]+a[i-1];
	}
	for(int i=0;i<=n;i++){
	for(int j=0;j<=n;j++){
		dp[i][j][0]=-1;
		dp[i][j][1]=-1;
	}
	}
	solve(0,n-1,0,a,pref);
	cout<<dp[0][n-1][0]<<"\n";
}

int main(){
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		get_accepted();
	}
}

