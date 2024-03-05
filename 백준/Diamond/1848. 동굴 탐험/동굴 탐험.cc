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

struct st{
	int v, w;
	bool operator< (const st& a) const{
		return w > a.w;
	}
};

vector<vp> g(5001);
int n, m;
int ans{MAX};
vp tmp;
vi idx(5001);

void solve(){
	cin >> n >> m;	
	for(int i{0}; i < m; ++i){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		g[a].push_back({b, c});
		g[b].push_back({a, d});
	}
	for(int i{0}; i < (int)g[1].size(); ++i){
		idx[g[1][i].first] = i;
		tmp.push_back({g[1][i].first, g[1][i].second});
	}
	for(int i{0}; i <= 12; ++i){
		priority_queue<st> pQ[2];
		vector<vi> dijk(n + 1, vi(2, MAX));
		for(auto& j : tmp){
			int k = (j.first >> i) & 1;
			pQ[k].push({j.first, j.second});
			dijk[j.first][k] = j.second;
		}
		for(int j{0}; j < 2; ++j){
			while(!pQ[j].empty()){
				int v{pQ[j].top().v};
				int w{pQ[j].top().w};
				pQ[j].pop();
				if(dijk[v][j] < w) continue;
				for(auto& next : g[v]){
					int nv{next.first};
					int nw{w + next.second};
					int a = (v >> i) & 1;
					if(nv == 1 && a == j) continue;
					if(dijk[nv][j] > nw){
						dijk[nv][j] = nw;
						pQ[j].push({nv, nw});
					}
				}
			}	
			ans = min(ans, dijk[1][j]);
		}
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