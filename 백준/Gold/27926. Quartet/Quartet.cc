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
    ll a, b, w;
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<st> vec(m);
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].w;
        g[vec[i].a].push_back({vec[i].b, vec[i].w});
        g[vec[i].b].push_back({vec[i].a, vec[i].w});
    }
    ll ans{0};
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.w > y.w;;
    });
    for(int i{1}; i <= n; ++i){
        sort(g[i].begin(), g[i].end(), [&](pi& x, pi& y){
            return x.second > y.second;
        });
    }
    if(m == 0){
        cout << 0; return 0;
    }
    else if(m == 1){
        cout << vec[0].w; return 0;
    }
    ans = vec[0].w + vec[1].w;
    for(int i{0}; i < m; ++i){
        ll a = vec[i].a;
        ll b = vec[i].b;
        ll w = vec[i].w;
        for(int j{0}; j < min(3, (int)g[a].size()); ++j){
            if(g[a][j].first == b) continue;
            for(int k{0}; k < min(3, (int)g[b].size()); ++k){
                if(g[b][k].first == a) continue;
                if(g[a][j].first != g[b][k].first){
                    ans = max(ans, w + g[a][j].second + g[b][k].second);
                }
            }
        }
    }
    cout << ans;
}
