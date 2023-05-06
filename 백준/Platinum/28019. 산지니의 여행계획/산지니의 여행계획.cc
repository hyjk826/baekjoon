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

int p[50001];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b; return true;
    }
    return false;
}

struct st{
    int a, b, c;
};

int main(){
	fastio;
	int n, m;
    cin >> n >> m;
    vector<st> vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.c > y.c;
    });
    iota(p + 1, p + n + 1, 1);
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        if(merge(vec[i].a, vec[i].b)){
            g[vec[i].a].push_back({vec[i].b, vec[i].c});
            g[vec[i].b].push_back({vec[i].a, vec[i].c});
        }
    }
    ll ans{0};
    function<void(int,int)> dfs = [&](int cur, int pre){
        for(auto& i : g[cur]){
            if(i.first == pre) continue;
            ans += i.second;
            dfs(i.first, cur);
            ans += i.second;
        }
    };
    int start;
    vl dist(n + 1, LLONG_MAX);
    cin >> start;
    dfs(start, -1);
    dist[start] = 0;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dist[i.first] == LLONG_MAX){
                dist[i.first] = dist[x] + i.second;
                Q.push(i.first);
            }
        }
    }
    ll mx{0};
    for(int i{1}; i <= n; ++i){
        mx = max(mx, dist[i]);
    }
    cout << ans - mx;
}
