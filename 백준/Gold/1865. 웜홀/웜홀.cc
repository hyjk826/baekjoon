// 2022-09-13
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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

struct st{
    int v, u, dis;
};


int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m, w;
        cin >> n >> m >> w;
        vector<st> edge;
        for(int i{0}; i < m; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            edge.push_back({a, b, c});
            edge.push_back({b, a, c});
        }
        for(int i{0}; i < w; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            edge.push_back({a, b, -c});
        }
        vi dis(n + 1, MAX);
        dis[1] = 0;
        bool f = false;
        for(int i{0}; i < n; ++i){
            bool flag = false;
            for(int j{0}; j < (int)edge.size(); ++j){
                int v = edge[j].v;
                int u = edge[j].u;
                int d = edge[j].dis;
                if(dis[v] + d < dis[u]){
                    dis[u] = dis[v] + d;
                    flag = true;
                }
            }
            if(i == n - 1 && flag){
                f = true;
            }
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
}
	

