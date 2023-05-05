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
#define MOD 1000000009
using namespace std;

int dp[1001][1001];

int main(){
	fastio;
    memset(dp, -1, sizeof(dp));
    function<int(int,int)> f = [&](int a, int b){
        if(a <= 0 || a < b) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        ret = 0;
        if(b == 1){
            if(a == 1 || a == 2 || a == 3) return ret = 1;
            else return ret = 0;
        }
        else{
            for(int i{1}; i <= 3; ++i){
                ret += f(a - i, b - 1);
                ret %= MOD;
            }
            return ret;
        }
    };
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        int ans{0};
        for(int i{1}; i <= b; ++i){
            ans += f(a, i);
            ans %= MOD;
        }
        cout << ans << "\n";    
    }
}
