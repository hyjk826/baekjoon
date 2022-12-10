// 2022-12-08
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

vector<vi> board(16, vi(16));
vi dp(1 << 16, -1);
int n;

int f(int state){
    if(dp[state] != -1) return dp[state];
    int& ret = dp[state];
    ret = (int)1e8;
    for(int i{0}; i < n; ++i){
        if((state >> i) & 1){
            for(int j{0}; j < n; ++j){
                if(i == j) continue;
                if((state >> j) & 1) ret = min(ret, f(state ^ (1 << i)) + board[j][i]);
            }
        }
    }
    return ret;
}



int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    string str;
    cin >> str;
    int p; cin >> p;
    int k{0};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == 'Y') k |= (1 << i);
    }
    dp[k] = 0;
    int ans{(int)1e8};
    for(int i{0}; i < (1 << n); ++i){
        if(__builtin_popcount(i) >= p){
            ans = min(ans, f(i));
        }
    }
    if(ans == (int)1e8) ans = -1;
    cout << ans;
}
	
