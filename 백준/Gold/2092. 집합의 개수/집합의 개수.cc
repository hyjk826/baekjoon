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
#define MOD 1000000
typedef long long ll;
using namespace std;

void solve(){
	int T, n, S, B;
    cin >> T >> n >> S >> B;
    vi ch(T + 1);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        ch[a]++;
    }
    vector<vi> dp(T + 1, vi(n + 1, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == T + 1){
            if(b == 0) return 1;
            else return 0;
        }
        int& ret = dp[a][b];
        if(ret != -1) return ret;
        ret = 0;
        if(ch[a] == 0) return ret = f(a + 1, b);
        else{
            ret = f(a + 1, b);
            for(int i{1}; i <= min(ch[a], b); ++i){
                ret += f(a + 1, b - i);
                ret %= MOD;
            }
            return ret;
        }
    };
    int ans{0};
    for(int i{S}; i <= B; ++i){
        ans += f(1, i);
        ans %= MOD;
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
