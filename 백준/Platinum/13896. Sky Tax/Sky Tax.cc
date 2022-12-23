// 2022-12-23
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

vi g[100001];
vi depth(100001, -1);
vector<vi> par(100001, vi(20, -1));
int n, root;

void bfs(){
    depth[root] = 0;
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i: g[x]){
            if(depth[i] == -1){
                depth[i] = depth[x] + 1;
                par[i][0] = x;
                Q.push(i);
            }
        }
    }
    for(int i{1}; i < 20; ++i){
        for(int j{1}; j <= n; ++j){
            if(par[j][i - 1] == -1) continue;
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int dif = depth[a] - depth[b];
    for(int i{0}; dif > 0; ++i){
        if(dif & 1) a = par[a][i];
        dif >>= 1;
    }
    if(a != b){
        for(int i{19}; i >=0; --i){
            if(par[a][i] != -1 && par[a][i] != par[b][i]){
                a = par[a][i];
                b = par[b][i];
            }
        }
        a = par[a][0];
    }
    return a;
}

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

int main(){
	fastio;
    int t;
    cin >> t;
    for(int T{0}; T < t; ++T){
        cout << "Case #" << T + 1 << ":\n";
        int q;
        cin >> n >> q >> root;
        for(int i{0}; i <= 100000; ++i){
            depth[i] = -1;
            g[i].clear();
            for(int j{0}; j < 20; ++j){
                par[i][j] = -1;
            }
        }
        for(int i{0}; i < n - 1; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bfs();
        vi sub(n + 1);
        function<void(int, int)> dfs = [&](int cur, int pre){
            sub[cur] = 1;
            for(auto& i : g[cur]){
                if(i == pre) continue;
                dfs(i, cur);
                sub[cur] += sub[i];
            }
        };
        dfs(root, -1);
        while(q--){
            int a, b;
            cin >> a >> b;
            if(a == 0) root = b;
            else{
                if(b == root){
                    cout << n << "\n";
                    continue;
                }
                int an = LCA(root, b);
                if(an == b){
                    int dis = dist(root, b);
                    dis--;
                    int k = root;
                    for(int i{0}; dis > 0; ++i){
                        if(dis & 1) k = par[k][i];
                        dis >>= 1;
                    }
                    cout << n - sub[k] << "\n";
                }
                else{
                    cout << sub[b] << "\n";
                }
            }
        }
    }
}
