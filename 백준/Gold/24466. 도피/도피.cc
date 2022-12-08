// 2022-12-08
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


ll mx{0};
vi ans;
int n, m;
vector<vp> g(101);
vector<vl> dp(101, vl(10, -1));

ll f(int a, int b){
    if(dp[a][b] != -1) return dp[a][b];
    if(a == 0 && b == 0) return dp[a][b] = (ll)1e18;
    dp[a][b] = 0;
    for(auto& i : g[a]){
        if(b){
            dp[a][b] += f(i.first, b - 1) / 100 * i.second;
        }
    }
    return dp[a][b];
}

int main() {
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[b].push_back({a, c});
    }
    for(int i{0}; i < n; ++i){
        ll k = f(i, 9);
        // cout << i << " " << k << "\n";
        if(k > mx){
            ans.clear();
            ans.push_back(i);
            mx = k;
        }
        else if(k == mx){
            ans.push_back(i);
        }
    }
    for(auto& i : ans) cout << i << " ";
    cout << "\n";
    if(mx == (ll)1e18) cout << "1." << string(18, '0');
    else cout << "0." << string(18 - to_string(mx).size(), '0') << mx; 
}
	
