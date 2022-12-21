// 2022-12-21
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

vi uni(1001);

int find(int a){
    if(a == uni[a]) return a;
    return uni[a] = find(uni[a]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        uni[a] = b;
        return true;
    }
    return false;
}

struct st{
    int a, b, w;
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<st> edge(m);
    for(int i{0}; i < m; ++i){
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }
    sort(edge.begin(), edge.end(), [&](st& a, st& b){
        return a.w < b.w;
    });
    int q;
    cin >> q;
    vector<vp> g(n + 1);
    int sum{0};
    for(int i{1}; i <= n; ++i){
        uni[i] = i;
    }
    for(int i{0}; i < m; ++i){
        if(Union(edge[i].a, edge[i].b)){
            g[edge[i].a].push_back({edge[i].b, edge[i].w});
            g[edge[i].b].push_back({edge[i].a, edge[i].w});
            sum += edge[i].w;
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        vp p(n + 1);
        queue<int> Q;
        Q.push(a);
        while(!Q.empty()){
            int v{Q.front()};
            Q.pop();
            for(auto& i : g[v]){
                if(p[i.first].first == 0){
                    p[i.first] = {v, i.second};
                    Q.push(i.first);
                }
            }
        }
        int k = b;
        int mx{0};
        while(1){
            mx = max(mx, p[k].second);
            k = p[k].first;
            if(k == a) break;
        }
        cout << sum - mx << "\n";
    }
}
	
