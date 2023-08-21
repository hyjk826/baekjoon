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
	int n, r;
    cin >> n >> r;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi vec(n + 1, -1);
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        vec[a] = b;
    }
    vi depth(n + 1);
    vi mn(n + 1, MAX);
    vi mx(n + 1, 0);
    function<void(int,int)> f = [&](int cur, int pre){
        depth[cur] = depth[pre] + 1;
        if(vec[cur] != -1) {
            mn[cur] = mx[cur] = vec[cur];
        }
        for(auto& i : g[cur]){
            if(i == pre) continue;
            f(i, cur);
            if(depth[cur] & 1) mx[cur] = max(mx[cur], mn[i]);
            else mn[cur] = min(mn[cur], mx[i]);
        }
    };
    f(r, 0);
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        if(depth[a] & 1) cout << mx[a] << "\n";
        else cout << mn[a] << "\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
