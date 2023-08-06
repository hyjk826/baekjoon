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

int dp[1000][1000];
vi vec(1000);
int n;

int f(int a, int b){
    if(a >= n || a >= b) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    dp[a][b] = f(a + 1, b);
    for(int i{a + 1}; i <= b; ++i){
        if(vec[i] == vec[a]) dp[a][b] = max(dp[a][b], f(a + 1, i - 1) + f(i + 1, b) + 1);
    }
    return dp[a][b];
}


void solve(){
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1);
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
