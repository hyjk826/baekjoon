// 2022-08-15
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    string s, t, r;
    cin >> s >> t >> r;
    int a = (int)s.size();
    int b = (int)t.size();
    int c = (int)r.size();
    vector<vector<vi> > dp(a + 1, vector<vi>(b + 1, vi(c + 1)));
    for(int i{1}; i <= a; ++i){
        for(int j{1}; j<= b; ++j){
            for(int k{1}; k <= c; ++k){
                if(s[i - 1] == t[j - 1] && t[j - 1] == r[k - 1]){
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else{
                    int mx{0};
                    for(int x{0}; x <= 1; ++x){
                        for(int y{0}; y <= 1; ++y){
                            for(int z{0}; z <= 1; ++z){
                                if(x == 0 && y == 0 && z == 0) continue;
                                dp[i][j][k] = max(dp[i][j][k], dp[i - x][j - y][k - z]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[a][b][c];
}

