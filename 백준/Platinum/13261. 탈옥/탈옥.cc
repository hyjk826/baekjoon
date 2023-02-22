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

const int sz = 8e3 + 10;
vl pre(sz);
vector<vl> dp(801, vl(sz, -1));
vector<vi> p(801, vi(sz, -1));

ll C(int a, int b){
    return (pre[b] - pre[a - 1]) * (b - a + 1);
}

void f(int t, int l, int r, int s, int e){
    if(l > r) return;
    int mid = (l + r) >> 1;
    for(int k{s}; k <= e; ++k){
        ll a = dp[t - 1][k] + C(k + 1, mid);
        if(dp[t][mid] == -1 || dp[t][mid] > a){
            dp[t][mid] = a;
            p[t][mid] = k;
        }
    }
    f(t, l, mid - 1, s, p[t][mid]);
    f(t, mid + 1, r, p[t][mid], e);
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        pre[i] = vec[i] + pre[i - 1];
    }
    for(int i{0}; i <= n; ++i){
        dp[1][i] = C(1, i);
        p[1][i] = 0;
    }
    for(int i{2}; i <= m; ++i){
        f(i, 0, n, 0, n);
    }
    cout << dp[m][n];
}
