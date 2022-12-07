// 2022-12-07
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

int n;
vector<vi> g((int)1e5);
vl sub;

void dfs(int cur, int pre){
    for(auto& i : g[cur]){
        if(i == pre) continue;
        dfs(i, cur);
        sub[cur] += sub[i];
    }
}

int main() {
	fastio;
	cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);        
    }
    vi A(n - 1);
    for(int i{0}; i < n - 1; ++i){
        cin >> A[i];
    }
    sub.resize(n, 1);
    dfs(0, -1);
    sort(A.begin(), A.end());
    ll ans{0};
    for(int i{0}; i < n; ++i){
        sub[i] = sub[i] * (n - sub[i]);
    }
    sort(sub.rbegin(), sub.rend());
    for(int i{0}; i < n; ++i){
        ans += 1LL * sub[i] * A[i];
        ans %= MOD;
    }
    cout << ans;
}
	
