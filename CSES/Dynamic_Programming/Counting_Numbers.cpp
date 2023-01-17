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
long long dp[19][10][2][2];
vector<int> nums;
int cunt=0;


long long call(int pos,int prev,bool chk,int f){
	if(pos==nums.size()){
		return 1;
	}
	if(prev!=-1&&dp[pos][prev][chk][f]!=-1) return dp[pos][prev][chk][f];
	long long res=0;
	int lmt;
	if(!chk){
		lmt=nums[pos];
	}
	else{
		lmt=9;
	}
	for(int dgt=0;dgt<=lmt;dgt++){
		int nf=f;
		if(dgt==prev){
			if(f==0){
				if(dgt==0){
				}
			}
			else{
				continue;
			}
		}
		if(dgt!=0){
			nf=1;
		}
		int nchk=chk;
		if(chk==0&&dgt<lmt){
			nchk=1;
		}
		res+=call(pos+1,dgt,nchk,nf);
	}
	return dp[pos][prev][chk][f]=res;
}

long long solve(long long b){
	for(int i=0;i<19;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<2;k++){
			dp[i][j][k][0]=-1;
			dp[i][j][k][1]=-1;
			}
		}
	}
	nums.clear();
	while(b!=0){
		int r=b%10;
		b/=10;
		nums.push_back(r);
	}
	reverse(nums.begin(),nums.end());
	return call(0,-1,0,0);
}

void get_accepted(){
	long long a,b;
	cin>>a>>b;
	cout<<solve(b)-solve(a-1);
}

int main(){
	int tt;
//	cin>>tt;
	tt=1;
	while(tt--){
		get_accepted();
	}
}

