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

int n;
const int sz = 100000 + 10;
int par[sz][20];
int depth[sz];
vector<vi> g(sz);
int root = 1;


void bfs(){
    memset(depth, -1, sizeof(depth));
    queue<int> Q;
    Q.push(root);
    depth[root] = 0;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(depth[i] == -1){
                depth[i] = depth[x] + 1;
                par[i][0] = x;
                Q.push(i);
            }
        }
    }
    for(int j{1}; j < 20; ++j){
        for(int i{1}; i <= n; ++i){
            if(par[i][j - 1] == -1) continue;
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i{0}; i < 20; ++i){
        if((diff >> i) & 1) a = par[a][i];
    }
    if(a != b){
        for(int i{19}; i >= 0; --i){
            if(par[a][i] != par[b][i]){
                a = par[a][i];
                b = par[b][i];
            }
        }
        a = par[a][0];
        b = par[a][0];
    }
    return a;
}


void solve(){
    cin >> n;
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs();
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
