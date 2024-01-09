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

int xx[]{-1,0,1,0,0};
int yy[]{0,-1,0,1,0};

void solve(){
	int n;
    cin >> n;
    vp vec(n + 1);
    for(int i{0}; i <= n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vector<vl> dp(n + 1, vl(5, -1));
    function<ll(int,int)> f = [&](int a, int b){
        if(a == n) return 0LL;
        if(dp[a][b] != -1) return dp[a][b];
        ll& ret = dp[a][b];
        ret = LLONG_MAX;
        int x = vec[a].first + xx[b];
        int y = vec[a].second + yy[b];
        for(int i{0}; i < 5; ++i){
            int nx{vec[a + 1].first + xx[i]};
            int ny{vec[a + 1].second + yy[i]};
            ret = min(ret, abs(x - nx) + abs(y - ny) + f(a + 1, i));
        }
        return ret;
    };
    cout << f(0, 4) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
