// 2022-11-16
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

int n, m;
string str;
vector<vi> dp;
vp g(26);


int f(int a, int b){
    if(dp[a][b] != -1) return dp[a][b];
    if(a > b || a == b) return 0;
    int ret{MAX};
    if(str[a] == str[b]) return f(a + 1, b - 1);    
    else{        
        ret = min(ret, min(g[str[b] - 'a'].first, g[str[b] - 'a'].second) + f(a, b - 1));
        ret = min(ret, min(g[str[a] - 'a'].first, g[str[a] - 'a'].second) + f(a + 1, b));
    }
    return dp[a][b] = ret;
}

int main() {
	fastio;
    cin >> n >> m >> str;
    dp.resize(m, vi(m, -1));
    for(int i{0}; i < n; ++i){
        char c;
        int a, b;
        cin >> c >> a >> b;
        g[c - 'a'] = {a, b};
    }
    cout << f(0, m - 1);
}
	

