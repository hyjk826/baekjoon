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

// from jason9319.tistory.com
struct hopcroft_karp {
    int n;
    vector<int> a, b, dist, match, work;
    vector<vector<int>> vt;
    hopcroft_karp(int n) :n(n) {
        a.assign(n + 1, -1);
        b.assign(n + 1, -1);
        dist.assign(n + 1, 0);
        match.assign(n + 1, 0);
        vt.resize(n + 1);
    }
    void addEdge(int x, int y) {
        vt[x].push_back(y);
    }
    void bfs() {
        queue<int> qu;
        for (int i = 1; i <= n; i++) {
            if (!match[i]) {
                dist[i] = 0;
                qu.push(i);
            }
            else
                dist[i] = MAX;
        }
        while (qu.size()) {
            int here = qu.front();
            qu.pop();
            for (auto there : vt[here]) {
                if (b[there] != -1 && dist[b[there]] == MAX) {
                    dist[b[there]] = dist[here] + 1;
                    qu.push(b[there]);
                }
            }
        }
    }
    bool dfs(int here) {
        for (int &i = work[here]; i < vt[here].size(); i++) {
            int there = vt[here][i];
            if (b[there] == -1 || dist[b[there]] == dist[here] + 1 && dfs(b[there])) {
                match[here] = true;
                a[here] = there;
                b[there] = here;
                return true;
            }
        }
        return false;
    }
    int solve() {
        int ret = 0;
        while (1) {
            work.assign(n + 1, 0);
            bfs();
            int flow = 0;
            for (int i = 1; i <= n; i++)
                if (!match[i] && dfs(i))flow++;
            if (!flow)break;
            ret += flow;
        }
        return ret;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<vp> tmp(n + 1);
    for(int i{1}; i <= n; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        tmp[i].push_back({a, b});
        tmp[i].push_back({c, d});
    }
    int l{0}, r{(int)1e6};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        hopcroft_karp hk(2 * n);
        for(int i{1}; i <= n; ++i){
            for(auto& j : tmp[i]){
                if(j.second <= mid){
                    hk.addEdge(i, j.first);
                }
            }
        }
        if(hk.solve() == n){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}