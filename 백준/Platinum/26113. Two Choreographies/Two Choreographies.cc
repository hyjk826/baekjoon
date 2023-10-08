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
vi G[sz];
vi depth(sz, -1);
vector<vi> par(sz, vi(20, -1));
int root = 1;
int n;

void bfs(int k){
    depth[k] = 0;
    queue<int> Q;
    Q.push(k);
    vi A;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();        
        A.push_back(x);
        for(auto& i: g[x]){
            if(depth[i] == -1){
                depth[i] = depth[x] + 1;
                par[i][0] = x;
                Q.push(i);
            }
        }
    }
    for(int i{1}; i < 20; ++i){
        for(auto& j : A){
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

void solve(){
    cin >> n;
    vp edge;
    for(int i{0}; i < 2 * n - 3; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        edge.push_back({a, b});
    }    
    vi ch(n + 1);
    for(int i{1}; i <= n; ++i){
        if(ch[i]) continue;
        ch[i] = 1;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& j : G[x]){
                if(ch[j]) continue;
                ch[j] = 1;
                g[j].push_back(x);
                g[x].push_back(j);
                Q.push(j);
            }
        }
        bfs(i);
    }
    vector<vp> ans(n);
    for(auto& i : edge){
        int k = LCA(i.first, i.second);
        int dist = depth[i.first] + depth[i.second] - 2 * depth[k];
        if(dist == 1) continue;
        ans[dist].push_back(i);
        if(ans[dist].size() == 2) break;
    }
    for(int i{2}; i < n; ++i){
        if(ans[i].size() == 2){
            function<vi(int,int)> f = [&](int a, int b){
                vi ret1;
                vi ret2;
                if(depth[a] < depth[b]) swap(a, b);
                while(depth[a] != depth[b]){
                    ret1.push_back(a);
                    a = par[a][0];
                }
                while(a != b){
                    ret1.push_back(a);
                    ret2.push_back(b);
                    a = par[a][0];
                    b = par[b][0];
                }
                ret1.push_back(a);
                reverse(ret2.begin(), ret2.end());
                for(auto& i : ret2) ret1.push_back(i);
                return ret1;
            };
            vi A = f(ans[i][0].first, ans[i][0].second);
            vi B = f(ans[i][1].first, ans[i][1].second);
            cout << A.size() << "\n";
            for(auto& i : A) cout << i << " ";
            cout << "\n";
            for(auto& i : B) cout << i << " ";
            return;            
        }
    }
    cout << -1 << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
