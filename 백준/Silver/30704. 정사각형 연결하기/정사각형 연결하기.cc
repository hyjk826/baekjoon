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
    int k = int(sqrt(n));
    int ans{MAX};
    for(int i{max(1, k - 2)}; i <= k + 2; ++i){
        for(int j{-1}; j <= 1; ++j){
            if(i * (i + j) >= n){
                ans = min(ans, 2 * (i + (i + j)));
            }
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
