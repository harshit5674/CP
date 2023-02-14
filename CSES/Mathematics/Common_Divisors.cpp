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

const int mxm=1e9+7;
const int mx=1e6+5;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int m[mx];

void get_accepted(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		m[x]++;
	}
	int ans=1;
	for(int i=2;i<=mx;i++){
		int cunt=0;
		for(int j=i;j<=mx;j+=i){
			if(m[j]){
				cunt+=m[j];
			}
		}
		if(cunt>=2){
			ans=max(ans,i);
		}
	}
	cout<<ans<<"\n";
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

