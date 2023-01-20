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
int dp[2002][2002][2];;
string s;


void get_accepted(){
	cin>>s;
	int n=s.size();
	for(int i=1;i<=n;i++){
		dp[i][i][s[i-1]-'0']=1;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[j]=='1'){
				dp[i+1][j+1][1]=max({dp[i+1][j][1],dp[i+1][j+1][1],dp[i+1][j][0]+1,dp[i+1][j][1]+1});
				dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i+1][j][0]);
			}
			else{
				dp[i+1][j+1][0]=max({dp[i+1][j][0],dp[i+1][j+1][0],dp[i+1][j][0]+1});
				dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i+1][j][1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j][0]=max(dp[i][j][1],dp[i][j][0]);
		}
	}
	for(int i=1;i<n;i++){
		if(s[i-1]=='0'){
			continue;
		}
		bool ok=true;
		for(int j=i+1;j<=n;j++){
			ok&=(dp[i][j][0]==dp[i+1][j][0]+1);
		}
		if(ok){
			s[i-1]='0';
		}
	}
	s[n-1]='0';
	cout<<s;
}

int main(){
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		get_accepted();
	}
}

