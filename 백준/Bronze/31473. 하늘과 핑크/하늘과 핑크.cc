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


void solve(){
	int n;
    cin >> n;
    vi A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    cout << accumulate(B.begin(), B.end(), 0) << " " << accumulate(A.begin(), A.end(), 0) << "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}