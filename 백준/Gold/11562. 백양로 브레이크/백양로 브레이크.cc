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

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};


void solve(){
	int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    vector<vi> g2(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(c == 0) {
            g[a].push_back(b);
            g2[b].push_back(a);
        }
        else{
            g[a].push_back(b);
            g[b].push_back(a);
        }        
    }
    vector<vi> ans(n + 1, vi(n + 1, MAX));
    for(int i{1}; i <= n; ++i){
        priority_queue<st> pQ;
        ans[i][i] = 0;
        pQ.push({i, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            if(ans[i][v] < w) continue;
            for(auto& j : g[v]){
                if(ans[i][j] > w){
                    ans[i][j] = w;
                    pQ.push({j, w});
                }
            }
            for(auto& j : g2[v]){
                if(ans[i][j] > w + 1){
                    ans[i][j] = w + 1;
                    pQ.push({j, w + 1});
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << "\n";
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
