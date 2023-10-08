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

// 1100000
// 0011111
// 0011011
// 0011101
// 0001111


void solve(){
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int ans{0};
    for(int i{19}; i >= 0; --i){
        int cnt{0};
        for(int j{0}; j < n; ++j){
            if(ans == 0){
                if((vec[j] >> i) & 1) cnt++;
            }
            else if((ans & vec[j]) == ans){
                if((vec[j] >> i) & 1) cnt++;
            }
        }
        if(cnt >= k) ans |= (1 << i);
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
