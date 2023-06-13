#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

pl extended_gcd(ll a, ll b) {
	if(b == 0) return make_pair(1, 0);
	pl t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

ll CRT_nocoprime(vector<ll> &M, vector<ll> &A) {
	ll retA=A[0], retM=M[0];
	for(int i=1; i<M.size(); ++i){
		ll m2=retM, a2=retA, g=gcd(M[i], retM);
		if((A[i]-a2)%g) return -1;
		retM=M[i]*m2/g;
		ll m=M[i]/g; ll v=((A[i]-a2)/g%m+m)%m;
		ll w=(extended_gcd(m2/g%m, M[i]/g).first%m+m)%m;
		retA=a2+v*w%m*m2;
	}
	return retA;
}


void solve(){
    vl M(3), A(3);
    for(int i{0}; i < 3; ++i){
        cin >> M[i];
    }    
    for(int i{0}; i < 3; ++i){
        cin >> A[i];
    }
    cout << CRT_nocoprime(M, A) << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
