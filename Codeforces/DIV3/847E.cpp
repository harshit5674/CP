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
	ll x;
	cin>>x;
	if(x%2==1){
		cout<<-1<<"\n";
		return;
	}
	int bx[33];
	int tt=x/2;
	x/=2;
	for(int i=0;i<33;i++){
		bx[i]=tt%2;
		tt/=2;
	}
	int ba[33]={0},bb[33]={0};
	for(int i=0;i<33;i++){
		if(bx[i]==1){
			ba[i]=1;
			bb[i]=1;
		}
	}
	x*=3;
	int bnx[33]={0};
	for(int i=0;i<33;i++){
		bnx[i]=x%2;
		x/=2;
	}
	for(int i=0;i<33;i++){
		if(bx[i]==0){
			if(bnx[i]==1){
				ba[i]=1;
				bb[i]=0;
			}
			else{
				ba[i]=0;
				bb[i]=0;
			}
		}
	}
	ll a=0,b=0;
	ll k=1;
	for(int i=0;i<33;i++){
		a+=k*(ll)(ba[i]);
		b+=k*(ll)(bb[i]);
		k*=2LL;
	}
	ll rt=a^b;
	ll rrt=a+b;
	if(rrt%2!=0){
		cout<<-1<<"\n";
		return;
	}
	rrt/=2;
	if(rrt!=rt){
		cout<<-1<<"\n";
		return;
	}
	cout<<a<<" "<<b<<"\n";
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

