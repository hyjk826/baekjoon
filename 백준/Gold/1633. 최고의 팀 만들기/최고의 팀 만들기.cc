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

int dp[1000][16][16];

void solve(){
    vp vec;
    int a, b;
    while(cin >> a >> b){
        vec.push_back({a, b});
    }
    int n = (int)vec.size();
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(b == 0 && c == 0) return 0;
        if(a >= n) return -MAX;
        int& ret = dp[a][b][c];
        if(ret != -1) return ret;
        ret = 0;
        if(b) ret = max(ret, f(a + 1, b - 1, c) + vec[a].first);
        if(c) ret = max(ret, f(a + 1, b, c - 1) + vec[a].second);
        ret = max(ret, f(a + 1, b , c));
        return ret;
    };
    cout << f(0, 15, 15) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
