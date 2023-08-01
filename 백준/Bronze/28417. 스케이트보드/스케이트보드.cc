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
    int mx{0};
    for(int i{0}; i < n; ++i){
        vi A(2), B(5);
        for(int j{0}; j < 2; ++j) cin >> A[j];
        for(int j{0}; j < 5; ++j) cin >> B[j];
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        int sum{0};
        sum += A[0];
        sum += B[0] + B[1];
        mx = max(mx, sum);
    }
    cout << mx << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
