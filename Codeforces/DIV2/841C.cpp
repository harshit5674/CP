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

void get_accepted(){
	int n;
	cin>>n;
	int m[2*n+1]={0};
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vt<int> v;
	for(int i=0;i<2*n+1;i++){
		m[i]=0;
	}
	for(int i=0;i*i<2*n;i++){
		v.pb(i*i);
	}
	m[0]=1;
	ll ans=0;
	int sum=0;
	for(int i=0;i<n;i++){
		sum^=a[i];
		for(auto x:v){
			if((sum^x)<2*n){
				ans+=(ll)m[sum^x];
			}
		}
		m[sum]++;
	}
	ll t=((ll)n*(n+1))/2;
	cout<<t-ans<<"\n";
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


