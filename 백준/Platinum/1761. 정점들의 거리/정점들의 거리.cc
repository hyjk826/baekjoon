// 2022-07-26
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
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vp graph[100000];
vi depth(100001, -1);
vector<vi> par(100001, vi(20, -1));
int root;
int n;

void bfs(){
    depth[root] = 0;
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i: graph[x]){
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
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int dif = depth[a] - depth[b];
    for(int i{0}; dif != 0; ++i){
        if(dif % 2 == 1) a = par[a][i];
        dif /= 2;
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

int main() {
	fastio;
    cin >> n;
    root = 1;    
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    bfs();
    vi dis(n + 1, -1);
    dis[1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : graph[x]){
            if(dis[i.first] == -1){
                dis[i.first] = dis[x] + i.second;
                Q.push(i.first);
            }
        }
    }
    int m;
    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << dis[a] + dis[b] - 2 * dis[LCA(a, b)] << "\n";
    }
}

