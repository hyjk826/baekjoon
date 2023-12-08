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
    int a, b, c;
};

void solve(){
	int n;
    cin >> n;
    vector<vp> g(201);
    for(int i{0}; i < n - 1; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[c].push_back({a, b});
    }
    vi p(n + 1);
    vi cnt(n + 1, 1);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int a){
        if(a == p[a]) return a;
        return p[a] = find(p[a]);
    };
    ll ans{0};
    for(int i{200}; i >= 1; --i){
        for(auto& j : g[i]){
            int a = j.first;
            int b = j.second;
            a = find(a);
            b = find(b);
            ans += 1LL * i * cnt[a] * cnt[b];
            cnt[b] += cnt[a];
            cnt[a] = 0;
            p[a] = b;
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
