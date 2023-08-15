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

int dp[100][10][10];


void solve(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    function<int(int,int,int)> f = [&](int a, int b, int c){
        if(a >= n) return 0;
        int& ret = dp[a][b][c];
        if(ret != -1) return ret;
        ret = MAX;
        int x = s[a] - '0';
        int y = t[a] - '0';
        x = (x + b) % 10;
        for(int i{-9}; i <= 9; ++i){
            for(int j{-9}; j <= 9; ++j){
                int tmp = x;
                tmp = (tmp + i + 10) % 10;
                tmp = (tmp + j + 10) % 10;
                int k = (y - tmp + 10) % 10;
                int q;
                if(j < 0) q = 10 + j;
                else q = j;
                ret = min(ret, (abs(i) + 2) / 3 + (abs(j) + 2) / 3 + (min(k, 10 - k) + 2) / 3 + f(a + 1, (c + q + k) % 10, k));
            }
        }
        return ret;
    };
    cout << f(0, 0, 0);
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
