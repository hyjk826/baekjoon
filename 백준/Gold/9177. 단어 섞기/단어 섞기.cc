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
    int t;
    cin >> t;
    for(int i{1}; i <= t; ++i){
        cout << "Data set " << i << ": ";
        string s, t, r;
        cin >> s >> t >> r;
        vector<vi> dp((int)s.size() + 1, vi(t.size() + 1, -1));
        dp[0][0] = 1;
        function<int(int,int)> f = [&](int a, int b){
            if(dp[a][b] != -1) return dp[a][b];
            dp[a][b] = 0;
            if(a >= 1 && s[a - 1] == r[a + b - 1]) dp[a][b] |= f(a - 1, b);
            if(b >= 1 && t[b - 1] == r[a + b - 1]) dp[a][b] |= f(a, b - 1);
            return dp[a][b];
        };
        if(f((int)s.size(), (int)t.size())) cout << "yes\n";
        else cout << "no\n";
    }
}
