// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m, v;
vi g[1001];
vi ch(1001);

void dfs(int x, int pre){
    cout << x << " ";
    for(auto& i : g[x]){
        if(ch[i] == 0){
            ch[i] = 1;
            dfs(i, x);
        }
    }
}

void bfs(){
    queue<int> Q;
    vi ch(n + 1);
    Q.push(v);
    ch[v] = 1;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        cout << x << " ";
        for(auto& i : g[x]){
            if(ch[i] == 0){
                ch[i] = 1;
                Q.push(i);
            }
        }
    }
}
int main(){
    fastio;
    cin >> n >> m >> v;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        sort(g[i].begin(), g[i].end());
    }
    ch[v] = 1;
    dfs(v, -1);
    cout << "\n";
    bfs();
}