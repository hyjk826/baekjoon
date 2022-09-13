// 2022-09-13
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

vector<vl> f(vector<vl> a, vector<vl>b) {
    vector<vl> ans(2, vl(2));
    for (int i{ 0 }; i < 2; ++i) {
        for (int j{ 0 }; j < 2; ++j) {
            for (int k{ 0 }; k < 2; ++k) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}


vector<vl> binpow(vector<vl> a, ll b) {
    vector<vl> ans(2, vl(2));
    for (int i{ 0 }; i < 2; ++i) {
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

int main() {
	fastio;
    ll n;
    cin >> n;
    vector<vl> vec(2, vl(2));
    vec = {{1, 1}, {1, 0}};
    vector<vl> r = binpow(vec, n);
    cout << r[1][0] % MOD;
}
	

