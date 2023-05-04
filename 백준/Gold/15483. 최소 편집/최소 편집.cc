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
    string s, t;
    cin >> s >> t;
    vector<vi> dp((int)s.size(), vi((int)t.size(), -1));
    function<int(int,int)> f = [&](int a, int b){
        if(a == (int)s.size()) return (int)t.size() - b;
        if(b == (int)t.size()) return (int)s.size() - a;
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        ret = MAX;
        if(s[a] == t[b]) ret = min(ret, f(a + 1, b + 1));
        else ret = min(ret, 1 + f(a + 1, b + 1));
        ret = min(ret, 1 + f(a + 1, b));
        ret = min(ret, 1 + f(a, b + 1));
        return ret;
    };
    cout << f(0, 0);
}
