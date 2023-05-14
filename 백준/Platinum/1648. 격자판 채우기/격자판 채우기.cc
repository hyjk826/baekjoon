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
#define MOD 9901
using namespace std;

int main(){
	fastio;
	int n, m;
    cin >> n >> m;
    vector<vi> dp(n * m, vi(1 << m, -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == n * m){
            if(b == 0) return 1;
            else return 0;
        }
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b]; 
        ret = 0;
        if(b & 1){
            ret += f(a + 1, b >> 1);
            ret %= MOD;
        }
        else{
            if(a % m < m - 1 && !(b & 2)){
                ret += f(a + 2, b >> 2);
                ret %= MOD;
            }
            if(a / m <= n - 2){
                ret += f(a + 1, (b >> 1) | (1 << m - 1));
                ret %= MOD;
            }
        }
        return ret;
    };
    cout << f(0, 0);
}
