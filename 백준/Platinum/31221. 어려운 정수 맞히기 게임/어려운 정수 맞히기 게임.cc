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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

int q{0};

void query(ll a, ll b){
	// q++;
	cout << "? " << a << " " << b << endl;
}

void res(ll k){
	// cout << "query : " << q << "\n";
	cout << "! " << k << endl;
}


void solve(){
	ll l{0}, r{(ll)1e9};
	ll b{-1};
	// ll a = 999999999999999;
	while(l <= r){
		ll mid{(l + r) >> 1};
		query(0, mid);
		char c;
		cin >> c;
		// ll k = a - mid * mid;
		// if(k == 0) c = '0';
		// else if (k < 0) c = '-';
		// else c = '+';
		if(c == '0'){
			res(mid * mid); return;
		}
		else if(c == '-'){
			r = mid - 1;
		}
		else{
			b = mid;
			l = mid + 1;
		}
	}
	l = 1; r = (b + 1) * (b + 1) - b * b;
	while(l <= r){
		ll mid{(l + r) >> 1};
		query(mid, b);
		char c;
		cin >> c;
		// ll k = (a - mid) - b * b;
		// if(k == 0) c = '0';
		// else if(k < 0) c = '-';
		// else c = '+';
		if(c == '0'){
			res(mid + b * b); return;
		}
		else if(c == '-'){
			r = mid - 1;
		}
		else l = mid + 1;
	}

}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
