// 2023-01-20
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

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        for(int j{1}; j <= m; ++j){
            cin >> board[i][j];
        }
    }
    vector<vl> dp(m + 1, vl(n + 1, -1));
    vector<vl> p(m + 1, vl(n + 1, -1));
    dp[0][0] = 0;
    for(int j{1}; j <= m; ++j){
        for(int i{n}; i >= 0; --i){
            for(int k{n - i}; k >= 0; --k){
                if(dp[j - 1][k] == -1) continue;
                if(dp[j][k + i] < dp[j - 1][k] + board[i][j]){
                    dp[j][k + i] = dp[j - 1][k] + board[i][j];
                    p[j][k + i] = i;
                }
            }
        }
    }
    ll k = *max_element(dp[m].begin(), dp[m].end());
    vi ans;
    for(int i{n}; i >= 0; --i){
        if(dp[m][i] == k){
            int a = i;
            int b = m;
            while(m){
                ans.push_back(p[b][a]);
                a -= p[b][a];
                b--;
                m--;
            }
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << k << "\n";
    for(auto& i : ans) cout << i << " ";
}
