// 2023-01-18
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

int main(){
	fastio;
    vector<vi> g(21);
    int n, k;
    cin >> n >> k;
    ll ans{0};
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        g[str.size()].push_back(i);
    }
    for(int i{2}; i <= 20; ++i){
        for(int j{0}; j < (int)g[i].size(); ++j){
            int idx = upper_bound(g[i].begin(), g[i].end(), g[i][j] + k) - g[i].begin();
            ans += idx - j - 1;
        }
    }
    cout << ans;
}
