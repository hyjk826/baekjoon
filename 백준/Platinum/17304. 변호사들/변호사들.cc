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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<set<int> > g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
    }
    vi ch(n + 1);
    vector<vi> g2(n + 1);
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            if(g[j].count(i)){
                g2[i].push_back(j);
            }
            else ch[j] = 1;
        }
    }
    vi visited(n + 1);
    vi finished(n + 1);
    int cycle{0};
    bool flag = false;
    function<void(int, int)> dfs = [&](int cur, int pre){
        visited[cur] = 1;
        if(ch[cur]) flag = true;
        for(auto& i : g2[cur]){
            if(i == pre) continue;
            if(visited[i] == 0){
                dfs(i, cur);
            }
            else if(!finished[i]){
                cycle++;
            }
        }
        finished[cur] = 1;
    };
    bool ok = true;
    for(int i{1}; i <= n; ++i){
        if(visited[i]) continue;
        flag = false;
        cycle = 0;
        dfs(i, -1);
        ok &= (flag || cycle > 0);
    }
    if(ok) cout << "YES";
    else cout << "NO";
}
