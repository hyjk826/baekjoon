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
    int n;
    cin >> n;
    vector<vp> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    int mn{0};
    int root{-1};
    vi ch((int)1e5 + 10);
    function<void(int,int,int)> dfs = [&](int cur, int pre, int sum){
        if(mn < sum){
            mn = sum;
            root = cur;
        }
        for(auto& i : g[cur]){
            if(i.first == pre || ch[i.first]) continue;
            dfs(i.first, cur, sum + i.second);
        }
    };
    int a, b;
    dfs(1, -1, 0);
    a = root;
    mn = 0;
    dfs(root, -1, 0);
    b = root;
    mn = 0;
    int idx{-1};
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0){
            idx = i; break;
        }
    }
    ch[a] = 1;
    mn = 0;
    dfs(idx, -1, 0);
    mn = 0;
    dfs(root, -1, 0);
    int ans = mn;
    ch[a] = 0;
    ch[b] = 1;
    mn = 0;
    dfs(idx, -1, 0);
    mn = 0;
    dfs(root, -1, 0);
    ans = max(ans, mn);
    cout << ans << "\n";
}
