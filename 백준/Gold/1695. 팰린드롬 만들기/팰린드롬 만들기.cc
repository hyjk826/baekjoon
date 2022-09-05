// 2022-09-05
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n;
vi vec(5000);
vector<vi> dp(5000, vi(5000, -1));

int f(int a, int b){
    if(a > b) return 0;
    if(dp[a][b] != -1) return dp[a][b];    
    if(vec[a] == vec[b]){
        return dp[a][b] = f(a + 1, b - 1);
    }
    else{
        return dp[a][b] = 1 + min(f(a + 1, b), f(a, b - 1));
    }
}
int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }    
    cout << f(0, n - 1);
}
	

