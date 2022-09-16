// 2022-09-16
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

vector<vi> g(100001);
vi ch(100001);
int n;

pi bfs(int s){
    vi dis(n + 1, -1);
    dis[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(dis[i] == -1){
                dis[i] = dis[x] + 1;
                Q.push(i);
            }
        }
    }
    int mx{1};
    for(int i{1}; i <= n; ++i){
        if(dis[i] > dis[mx]){
            mx = i;
        }
    }
    return {mx, dis[mx]};
}

bool flag = false;
int a{-1}, b{-1};

void dfs(int v, int pre){
    ch[v] = 1;
    if(v == b){
        flag = true;
        return;
    }
    for(auto& i : g[v]){
        if(i == pre) continue;
        dfs(i, v);
        if(flag) return;
    }
    ch[v] = 0;
}

int mx{0};

void dfs2(int v, int pre, int dis){
    mx = max(mx, dis);
    for(auto& i : g[v]){
        if(i == pre || ch[i]) continue;
        dfs2(i, v, dis + 1);
    }
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    a = 1;
    pi x = bfs(a);
    b = x.first;
    x = bfs(b);
    a = x.first;
    int ans = x.second;
    dfs(a, -1);
    for(int i{1}; i <= n; ++i){
        if(ch[i]){
            dfs2(i, -1, 0);
        }
    }
    if(mx == 0) cout << 0 << "\n";
    else cout << ans + mx + 1;
}