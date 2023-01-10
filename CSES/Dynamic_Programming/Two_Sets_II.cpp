#include<bits/stdc++.h>

using namespace std;

const int mxm=1e9+7;
const int mx=2e5+5;
long long dp[505][125300];
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void get_accepted(){
	int n;
	cin>>n;
	int e=n*(n+1);
	e/=2;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=e;j++){
			dp[i][j]=-1;
		}
	}
	dp[1][1]=1;
	dp[1][0]=1;
	if(e%2!=0){
		cout<<0<<"\n";
		return;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=e;j++){
			if(dp[i-1][j]!=-1){
				dp[i][j]=max(dp[i][j],0LL);
				dp[i][j]+=dp[i-1][j];
				dp[i][j]%=(long long)mxm;
			}
			if(j+i>e){
				continue;
			}
			if(dp[i-1][j]!=-1){
				dp[i][j+i]=max(dp[i][j+i],0LL);
				dp[i][j+i]+=dp[i-1][j];
				dp[i][j+i]%=(long long)mxm;
			}
		}
	} 
	long long g=binpow(2,mxm-2,mxm);
	dp[n][e/2]*=g;
	dp[n][e/2]%=mxm;
	cout<<dp[n][e/2];
}

int main(){
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		get_accepted();
	}
}

