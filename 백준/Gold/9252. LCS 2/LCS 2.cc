// 2022-06-23
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    string s, t;
    cin >> s >> t;
    vector<vi> dp((int)s.size() + 1, vi(t.size() + 1));
    for(int i{1}; i <= (int)s.size(); ++i){
        for(int j{1}; j <= (int)t.size(); ++j){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    pi p = {(int)s.size(), (int)t.size()};
    string ans;
    while(1){
        if(p.first == 0 || p.second == 0) break;
        if(s[p.first - 1] == t[p.second - 1]){
            ans += s[p.first - 1];
            p.first--;
            p.second--;
        }
        else{
            if(dp[p.first][p.second] == dp[p.first - 1][p.second]){
                p.first--;
            }
            else p.second--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << dp[(int)s.size()][(int)t.size()] << "\n";
    cout << ans;
}
