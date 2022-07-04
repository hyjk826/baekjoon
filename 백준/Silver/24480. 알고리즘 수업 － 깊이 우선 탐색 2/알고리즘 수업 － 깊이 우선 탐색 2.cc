// 2022-07-05
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
vi ans(100001, -1);
int n, m, s;
int cnt{1};

void dfs(int v){
    ans[v] = cnt++;
    for(auto& i : graph[v]){
        if(ans[i] == -1){
            dfs(i);
        }
    }
}
int main(){
    fastio;    
    cin >> n >> m >> s;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    dfs(s);
    for(int i{1}; i <= n; ++i){
        if(ans[i] == -1) cout << 0 << "\n";
        else cout << ans[i] << "\n";
    }
}