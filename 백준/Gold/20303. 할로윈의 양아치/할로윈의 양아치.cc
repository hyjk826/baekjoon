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

void solve(){
	int n, m, k;
    cin >> n >> m >> k;
    vi A(n + 1);
    for(int i{1}; i <= n; ++i) cin >> A[i];
    vi ch(n + 1);
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vp tmp;
    for(int i{1}; i <= n; ++i){
        if(ch[i]) continue;
        queue<int> Q;
        Q.push(i);
        ch[i] = 1;
        int sum{0};
        int cnt{0};
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            cnt++;
            sum += A[x];
            for(auto& j : g[x]){
                if(ch[j] == 0){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
        tmp.push_back({cnt, sum});
    }
    vi dp(k, -1);
    dp[0] = 0;
    for(auto& i : tmp){ 
        for(int j{k - i.first - 1}; j >= 0; --j){
            if(dp[j] == -1) continue;
            dp[j + i.first] = max(dp[j + i.first], dp[j] + i.second);
        }
    }
    int ans{0};
    for(int i{k - 1}; i >= 0; --i){
        ans = max(ans, dp[i]);
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
