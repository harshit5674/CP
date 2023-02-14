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
	ll n;
	cin>>n;
	ll sum=0;
	map<int,ll> m;
	while(n%2==0){
		m[2]++;
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2){
		while(n%i==0){
			n/=i;
			m[i]++;
		}
	}
	if(n>1){
		m[n]++;
	}
	map<int,ll> m1;
	ll k=1;
	vt<pair<int,int>> v;
	for(auto x:m){
		v.pb({x.second,x.first});
		k*=x.first;
	}
	int cunt=0;
	int rem=0;
	sort(all(v));
	for(auto x:v){
		ll e=x.first;
		e-=rem;
		if(e<=0){
			k/=x.second;
			continue;
		}
		else{
			ll y=1;
			y=k*e;
			sum+=y;
			k/=x.second;
			rem+=e;
		}
	}
	cout<<sum<<"\n";
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

