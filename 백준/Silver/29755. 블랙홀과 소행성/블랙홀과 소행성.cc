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
	int n, m;
    cin >> n >> m;
    vi B(n), A(m), W(m);
    for(auto& i : B) cin >> i;
    for(int i{0}; i < m; ++i){
        cin >> A[i] >> W[i];
    }
    sort(B.begin(), B.end());
    int ans{0};
    for(int i{0}; i < m; ++i){
        int k = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        int l = k - 1;
        int r = k;
        int mn{MAX};
        if(l != -1) mn = min(mn, abs(A[i]- B[l]) * W[i]);
        if(r != n) mn = min(mn, abs(A[i]- B[r]) * W[i]);
        ans = max(ans, mn);
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
