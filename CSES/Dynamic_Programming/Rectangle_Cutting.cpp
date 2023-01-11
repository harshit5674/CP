#include<bits/stdc++.h>

using namespace std;

const int mxm=1e9+7;
const int mx=2e5+5;
long long dp[505][505];
long long solve(int a,int b){
	if(a==b){
		return 0;
	}
	if(dp[a][b]!=1000000000000000){
		return dp[a][b];
	}
	for(int i=1;i<a;i++){
		dp[a][b]=min(dp[a][b],solve(a-i,b)+solve(i,b)+1);
	}
	for(int i=1;i<b;i++){
		dp[a][b]=min(dp[a][b],solve(a,b-i)+solve(a,i)+1);
	}
	return dp[a][b];
}

void get_accepted(){
	int a,b;
	cin>>a>>b;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			dp[i][j]=1000000000000000;
		}
	}
	solve(a,b);
	if(dp[a][b]==1000000000000000){
		cout<<0<<"\n";
		return;
	}
	cout<<dp[a][b];
}

int main(){
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		get_accepted();
	}
}

