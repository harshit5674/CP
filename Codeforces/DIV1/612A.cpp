#include<bits/stdc++.h>
using namespace std;

const int mxm=1e9+7;
const int mx=3e5+5;

int dp[102][53][53][2]={0};;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<=n;i++){
		for(int j=0;j<53;j++){
			for(int k=0;k<53;k++){
				dp[i][j][k][0]=mxm;
				dp[i][j][k][1]=mxm;
			}
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dp[0][0][0][1]=0;
	dp[0][0][0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=(n+1)/2;k++){
				if(a[i]!=0){
					if(a[i]%2==0){
						if(j>0)
							dp[i+1][j][k][0]=min(dp[i][j-1][k][0],dp[i][j-1][k][1]+1);
					}
					else{
						if(k>0)
							dp[i+1][j][k][1]=min(dp[i][j][k-1][1],dp[i][j][k-1][0]+1);
					}
				}
				else{
					if(j>0){
						dp[i+1][j][k][0]=min(dp[i][j-1][k][0],dp[i][j-1][k][1]+1);
					}
					if(k>0)
						dp[i+1][j][k][1]=min(dp[i+1][j][k][1],min(dp[i][j][k-1][1],dp[i][j][k-1][0]+1));
				}
			}
		}
	}
	cout<<min(dp[n][n/2][(n+1)/2][0],dp[n][n/2][(n+1)/2][1]);
}

