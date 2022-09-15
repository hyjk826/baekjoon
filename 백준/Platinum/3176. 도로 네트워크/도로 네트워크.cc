// 2022-09-15
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

vp graph[100001];
vi depth(100001, -1);
vector<vi> par(100001, vi(20, -1));
vector<vi> mn(100001, vi(20));
vector<vi> mx(100001, vi(20));
int root;
int n;

void bfs() {
    depth[root] = 0;
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()) {
        int x{ Q.front() };
        Q.pop();
        for (auto& i : graph[x]) {
            if (depth[i.first] == -1) {
                depth[i.first] = depth[x] + 1;
                par[i.first][0] = x;
                mn[i.first][0] = i.second;
                mx[i.first][0] = i.second;
                Q.push(i.first);
            }
        }
    }
    for (int i{ 1 }; i < 20; ++i) {
        for (int j{ 1 }; j <= n; ++j) {
            if (par[j][i - 1] == -1) continue;            
            par[j][i] = par[par[j][i - 1]][i - 1];
            mn[j][i] = min(mn[par[j][i - 1]][i - 1], mn[j][i - 1]);
            mx[j][i] = max(mx[par[j][i - 1]][i - 1], mx[j][i - 1]);
        }
    }
}

pi f(int a, int b) {
    pi r = { MAX, 0 };
    if (depth[a] < depth[b]) swap(a, b);
    int dif = depth[a] - depth[b];
    for (int i{ 0 }; dif > 0; ++i) {
        if (dif & 1) {
            r.first = min(r.first, mn[a][i]);
            r.second = max(r.second, mx[a][i]);
            a = par[a][i];
        }
        dif >>= 1;
    }
    if (a != b) {
        for (int i{ 19 }; i >= 0; --i) {
            if (par[a][i] != -1 && par[a][i] != par[b][i]) {
                r.first = min(r.first, mn[a][i]);
                r.first = min(r.first, mn[b][i]);
                r.second = max(r.second, mx[a][i]);
                r.second = max(r.second, mx[b][i]);                
                a = par[a][i];
                b = par[b][i];
            }
        }
        r.first = min(r.first, mn[a][0]);
        r.first = min(r.first, mn[b][0]);
        r.second = max(r.second, mx[a][0]);
        r.second = max(r.second, mx[b][0]);
    }
    return r;
}

int main() {
    fastio;
    cin >> n;
    for (int i{ 0 }; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    root = 1;
    bfs();
    int m;
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        auto p = f(a, b);
        cout << p.first << " " << p.second << "\n";
    }
}


