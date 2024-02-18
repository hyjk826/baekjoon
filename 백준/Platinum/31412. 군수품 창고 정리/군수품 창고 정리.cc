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
    vl A(n + 1), B(m);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
        A[i] += A[i - 1];
    }
    for(auto& i : B) cin >> i;
    sort(B.begin(), B.end());
    ll l{1}, r{(ll)1e12};
    ll ans{-1};
    while(l <= r){
        ll mid{(l + r) >> 1};        
        bool flag = false;
        do{
            int idx{0};
            for(int i{0}; i < m; ++i){
                ll k = A[idx] + B[i] * mid;
                int a = upper_bound(A.begin(), A.end(), k) - A.begin();
                if(a - idx <= 1) break;
                idx = a - 1;
                if(idx == n) break;
            }
            if(idx == n){
                flag = true; break;
            }
        }while(next_permutation(B.begin(), B.end()));
        if(flag){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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