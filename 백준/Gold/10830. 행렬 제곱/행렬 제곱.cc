// 2022-01-13
#include <bits/stdc++.h>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

int n;
ll k;

vector<vi> f(vector<vi> a, vector<vi>b) {
    vector<vi> ans(n, vi(n));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < n; ++j) {
            for (int k{ 0 }; k < n; ++k) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= 1000;
            }
        }
    }
    return ans;
}

vector<vi> binpow(vector<vi> a, ll b) {
    vector<vi> ans(n, vi(n));
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

int main() {
    fastio;
    cin >> n >> k;
    vector<vi> A(n, vi(n));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    auto ans = binpow(A, k);
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}