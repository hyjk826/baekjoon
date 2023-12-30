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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

int dijk[100001][12];

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

void solve(){
	int n, m, k;
    cin >> n >> m >> k;
    vector<vp> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    for(int i{1}; i <= n; ++i){
        for(int j{0}; j < 12; ++j){
            dijk[i][j] = MAX;
        }
    }
    priority_queue<st> pQ;
    pQ.push({12, 0});
    dijk[1][0] = 0;
    while(!pQ.empty()){
        int x{pQ.top().v / 12};
        int y{pQ.top().v % 12};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y] < w) continue;
        for(auto& i : g[x]){
            int nv{i.first};
            int nw{w + i.second};
            if(dijk[nv][nw % 12] > nw){
                dijk[nv][nw % 12] = nw;
                pQ.push({nv * 12 + nw % 12, nw});
            }
        }
    }
    if(dijk[n][k % 12] <= k) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
