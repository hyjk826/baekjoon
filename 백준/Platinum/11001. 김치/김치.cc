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


ll dp[100000];
ll A[100000];
ll B[100000];

ll C(int j, int i){
    return 1LL * (i - j) * A[i] + B[j];
}

int n, d;

void f(int l, int r, int s, int e){
    if(l > r) return;
    int mid = (l + r) >> 1;
    int idx{-1};
    for(int k{max(s, mid - d)}; k <= e && k <= mid; ++k){
        ll a =  C(k , mid);
        if(dp[mid] < a){
            dp[mid] = a;
            idx = k;
        }
    }
    f(l, mid - 1, s, idx);
    f(mid + 1, r, idx, e);
}

void solve(){
    cin >> n >> d;
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }
    f(0, n - 1, 0, n - 1);
    cout << *max_element(dp, dp + n) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}