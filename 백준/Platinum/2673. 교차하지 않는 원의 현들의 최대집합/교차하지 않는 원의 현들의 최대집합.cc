// 2022-12-29
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
    int n;
    cin >> n;
    vector<vi> ch(101, vi(101));
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        ch[a][b] = ch[b][a] = 1;
    }
    vector<vi> dp(101, vi(101, -1));
    function<int(int, int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        dp[a][b] = 0;
        for(int i{a}; i < b; ++i){
            dp[a][b] = max(dp[a][b], f(a, i) + f(i, b) + ch[a][b]);
        }
        return dp[a][b];
    };
    cout << f(1, 100);
}
