// 2022-08-17
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

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<vi> g(k + 1);
    vi vec(n);
    for (int i{ 0 }; i < n; ++i) {
        cin >> vec[i];
        g[vec[i]].push_back(i);
    }
    int cnt{ 0 };
    int a{ -1 };
    while (1) {
        int mx{ -1 };
        bool flag = false;
        for (int i{ 1 }; i <= k; ++i) {
            auto it = upper_bound(g[i].begin(), g[i].end(), a);
            if (it == g[i].end()) {
                flag = true;
                break;
            }
            mx = max(mx, *it);
        }
        a = mx;
        cnt++;
        if (flag) {
            break;
        }
    }
    cout << cnt;
}