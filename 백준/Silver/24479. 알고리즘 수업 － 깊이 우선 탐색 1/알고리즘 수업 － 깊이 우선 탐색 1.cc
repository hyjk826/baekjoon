// 2022-05-31
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi graph[100001];
vi ans(100001);
vi ch(100001);
int cnt{1};
void dfs(int v, int p){
    ans[v] = cnt;
    for(auto& u : graph[v]){
        if(ch[u] == 0){
            ch[u] = 1;
            cnt++;
            dfs(u, v);
        }
    }
}
int main(){
    fastio;
    int n, m, r;
    cin >> n >> m >> r;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        sort(graph[i].begin(), graph[i].end());
    }
    ch[r] = 1;
    dfs(r, -1);
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << "\n";
    }
}