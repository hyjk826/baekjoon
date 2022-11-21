// 2022-11-20
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

int main() {
	fastio;	
	int n;
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int C, N, CN, NC;
    C = N = CN = NC = 0;
    for(int i{0}; i < n; ++i){
        int a, b;
        a = b = 0;
        bool f1, f2;
        f1 = f2 = false;
        for(int j{0}; j < (int)vec[i].size(); ++j){
            if(vec[i][j] == 'N') {
                a++;
                f1 = true;   
            }
            else if(vec[i][j] == 'C') {
                b++;
                if(f1) f2 = true;
            }
        }
        if(a == 0){
            C++;
        }
        else if(b == 0){
            N++;
        }
        else{
            if(f1 && f2) NC++;
            else CN++;
        }
    }
    vl dp(n + 1);
    dp[0] = 1;
    for(int i{1}; i <= n; ++i){
        dp[i] = (dp[i - 1] * i) + 1;
        dp[i] %= MOD;
    }
    ll ans = dp[n];
    ans = (ans - (((dp[C] * dp[N]) % MOD) * (CN + 1)) % MOD + MOD) % MOD;
    cout << ans;
}
	

