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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vi> dp(101, vi(101, -1));
    dp[1][1] = 0;
    function<int(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        int flag = false;
        for(int j{1}; j < a; ++j){
            flag |= (f(j, a - j) == 0);
        }
        for(int j{1}; j < b; ++j){
            flag |= (f(j, b - j) == 0);
        }
        if(flag) return dp[a][b] = 1;
        else return dp[a][b] = 0;
    };
    if(f(n, m)) cout << "A\n";
    else cout << "B\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
