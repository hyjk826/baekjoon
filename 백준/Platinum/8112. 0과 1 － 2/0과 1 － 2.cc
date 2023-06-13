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
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n"; return;
    }
    vp dp(1000000, {-1,-1});
    dp[1] = {-1, 1};
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(int i{0}; i < 2; ++i){
            int nx{(x * 10 + i) % n};
            if(dp[nx].second == -1){
                dp[nx] = {x, i};
                Q.push(nx);
            }
        }
    }
    if(dp[0].second == -1) cout << "BRAK\n";
    else{
        int k = 0;
        string ans;
        while(1){
            if(k == -1) break;
            ans += char('0' + dp[k].second);
            k = dp[k].first;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
