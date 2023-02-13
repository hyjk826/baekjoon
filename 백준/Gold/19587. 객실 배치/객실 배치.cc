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

int n = 2;

vector<vl> f(vector<vl> a, vector<vl>b) {
    vector<vl> ans(n, vl(n));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < n; ++j) {
            for (int k{ 0 }; k < n; ++k) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}


vector<vl> binpow(vector<vl> a, ll b) {
    vector<vl> ans(n, vl(n));
    for (int i{ 0 }; i < n; ++i) {
        ans[i][i] = 1;
    }
    if (b == 0) return ans;
    auto k = binpow(a, b / 2);
    if (b % 2) {
        return f(f(k, k), a);
    }
    else {
        return f(k, k);
    }
}

int main(){
	fastio;
    ll n;
    cin >> n;
    vector<vl> A = {
        {1, 1},
        {2, 1}
    };
    auto ret = binpow(A, n);
    cout << (ret[0][0] + ret[1][0]) % MOD;
}
