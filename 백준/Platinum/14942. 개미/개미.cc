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

const int sz = 1e5 + 10;
vp g[sz];
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
vi dis(sz, -1);
int root = 1;
int n;

void bfs(){
    depth[root] = 0;
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i: g[x]){
            if(depth[i.first] == -1){
                depth[i.first] = depth[x] + 1;
                par[i.first][0] = x;
                Q.push(i.first);
            }
        }
    }
    for(int i{1}; i < 20; ++i){
        for(int j{1}; j <= n; ++j){
            if(par[j][i - 1] == -1) continue;
            par[j][i] = par[par[j][i - 1]][i - 1];
        }
    }
    dis[root] = 0;
    Q.push(root);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dis[i.first] == -1){
                dis[i.first] = dis[x] + i.second;
                Q.push(i.first);
            }
        }
    }
}

int main(){
	fastio;
    cin >> n;
    vi A(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    root = 1;
    bfs();
    for(int i{1}; i <= n; ++i){
        int a = i;
        for(int j{19}; j >= 0; --j){
            if(par[a][j] == -1) continue;
            if(dis[a] - dis[par[a][j]] <= A[i]){
                A[i] -= dis[a] - dis[par[a][j]];
                a = par[a][j];
            }
        }
        cout << a << "\n";
    }
}
