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

void solve(){   
    int n, m;
    cin >> n >> m;
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<double> ch(n + 1);
    ch[1] = 100;
    for(int i{1}; i <= n; ++i){
        for(auto& j : g[i]){
            ch[j] += ch[i] / (int)g[i].size();
        }
    }
    double ans{0};
    cout << fixed << setprecision(20);
    for(int i{1}; i <= n; ++i){
        if(g[i].size()) continue;
        ans = max(ans, ch[i]);
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
