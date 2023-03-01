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
vi g[sz];
int depth[sz];
int par[sz][20];
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
            if(depth[i] == -1){
                depth[i] = depth[x] + 1;
                par[i][0] = x;
                Q.push(i);
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
    for(int i{0}; dif > 0; ++i){
        if(dif & 1) a = par[a][i];
        dif >>= 1;
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

int dist(int u, int v){
    return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
}

int getkth(int u, int v, int k){
	int lca = LCA(u, v);
	int diff = depth[u] - depth[lca];
	if(diff >= k){
		for(int i=0; k; i++){
			if(k & 1) u = par[u][i];
			k >>= 1;
		}
		return u;
	}

	k = depth[v] - depth[lca] + diff - k;
	for(int i=0; k; i++){
		if(k & 1) v = par[v][i];
		k >>= 1;
	}
	return v;
}

int getMid(int a, int b){
    int d = dist(a, b);
    if(d & 1) return -1;
    return getkth(a, b, d / 2);
}

int main(){
	fastio;
    memset(par, -1, sizeof(par));
    memset(depth, -1, sizeof(depth));
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
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b && b == c) cout << a << "\n";
        else if(a == b || b == c || a == c){
            if(a == b) cout << getMid(a, c) << "\n";
            else cout << getMid(a, b) << "\n";
        }
        else{
            vi vec;
            vec.push_back(getMid(a, b));
            vec.push_back(getMid(a, c));
            vec.push_back(getMid(b, c));
            int ans{-1};
            for(int i{0}; i < 3; ++i){
                if(vec[i] == -1) continue;
                int x = dist(vec[i], a);
                int y = dist(vec[i], b);
                int z = dist(vec[i], c);
                if(x == y && y == z && x == z) ans = vec[i];
            }
            cout << ans << "\n";
        }
    }
}
