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

int dp[101][101][101][101];

int main(){
	fastio;
    for(int i{0}; i <= 100; ++i){
        for(int j{0}; j <= 100; ++j){
            for(int a{0}; a <= 100; ++a){
                for(int b{0}; b <= 100; ++b){
                    dp[i][j][a][b] = -MAX;
                }
            }
        }
    }
    for(int i{0}; i <= 100; ++i){
        dp[0][0][0][i] = 0;
    }
    int a, b, c;
    cin >> a >> b >> c;
    function<int(int,int,int,int)> f = [&](int A, int B, int C, int T){
        if(dp[A][B][C][T] != -MAX) return dp[A][B][C][T];
        int& ret = dp[A][B][C][T];
        if(A) ret = max(ret, min(A, T) - f(A - min(A, T), B, C, T + 1));
        if(B) ret = max(ret, min(B, T) - f(A, B - min(B, T), C, T + 1));
        if(C) ret = max(ret, min(C, T) - f(A, B, C - min(C, T), T + 1));
        return ret;
    };
    int ans = f(a, b, c, 1);
    if(ans > 0) cout << "F";
    else if(ans < 0) cout << "S";
    else cout << "D";
}
