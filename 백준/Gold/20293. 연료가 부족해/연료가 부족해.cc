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

struct st{
    int x, y, c;
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<st> vec;
    vec.push_back({1, 1, 0});
    for(int i{0}; i < k; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        vec.push_back({x, y, c});
    }
    vec.push_back({n, m, 0});
    vector<vi> g(k + 2);
    for(int i{0}; i < k + 2; ++i){
        for(int j{0}; j < k + 2; ++j){
            if(i == j) continue;
            if(vec[i].x <= vec[j].x && vec[i].y <= vec[j].y){
                g[j].push_back(i);
            }
        }
    }
    int l{0}, r{n + m - 2};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        vi dp(k + 2, -1);
        dp[0] = mid;
        function<int(int)> f = [&](int cur){
            if(dp[cur] != -1) return dp[cur];
            int mx{-(int)1e9};
            for(auto& i : g[cur]){
                int k = f(i);
                int dist = vec[cur].x - vec[i].x + vec[cur].y - vec[i].y;
                if(k < dist) continue;
                mx = max(mx, k - dist + vec[cur].c);
            }
            return dp[cur] = mx;
        };
        if(f(k + 1) >= 0){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
