#include<bits/stdc++.h>
using namespace std;
 
const int mxm=1e9+7;
const int mx=2e5+5;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	int d[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			d[i][j]=mxm;
		}
	}
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		queue<int> q;
		q.push(i);
		bool visited[n+1]={0};
		visited[i]=1;
		while(!q.empty()){
			int s=q.front();
			q.pop();
			for(int j=0;j<n;j++){
				if(a[s-1][j]=='1'){
					if(!visited[j+1]){
						visited[j+1]=1;
						d[i][j+1]=d[i][s]+1;
						q.push(j+1);
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<d[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	vector<int> ans;
	ans.push_back(b[0]);
	for(int i=1;i<m-1;i++){
		if(d[ans.back()][b[i+1]]==d[ans.back()][b[i]]+d[b[i]][b[i+1]]){
			;
		}
		else{
			ans.push_back(b[i]);
		}
	}
	ans.push_back(b[m-1]);
	cout<<ans.size()<<"\n";
	for(auto x:ans){
		cout<<x<<" ";
	}
}

