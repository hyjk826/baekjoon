// 2022-08-17
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n, m, q;
    cin >> n >> m >> q;
    vl M(m + 1);
    vector<vl> g(m);
    vi ch(2001);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        for(int j{0}; j < a * 2 + 1; ++j){
            ll b;
            cin >> b;
            g[i].push_back(b);
        }
    }
    for(int i{0}; i <= m; ++i){
        cin >> M[i];
    }
    for(int i{0}; i < m; ++i){
        int sz = g[i].size() / 2;
        for(int j{sz}; j < (int)g[i].size(); ++j){
            g[i][j] *= M[i];
        }
    }
    for(int i{0}; i < m; ++i){
        int sz = g[i].size() / 2;
        for(int j{0}; j < sz; ++j){
            ch[g[i][j] - 1] += g[i][j + sz];
        }
    }
    while(q--){
        vl vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        vl A;
        ll ans{M.back()};
        for(int i{0}; i < m; ++i){
            ans += g[i].back();
        }
        for(int i{0}; i < n; ++i){
            ans += ch[i] * vec[i];
        }
        cout << ans << "\n";
    }
}