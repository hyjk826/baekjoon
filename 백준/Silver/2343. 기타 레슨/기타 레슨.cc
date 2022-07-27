// 2022-07-28
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
    vi vec(n);
    for (int i{ 0 }; i < n; ++i) {
        cin >> vec[i];
    }
    int l{ 1 }, r{MAX };
    int ans{ MAX};
    while (l <= r) {
        int m{ (l + r) / 2 };
        int cnt{ 1 };
        int sum{ 0 };
        bool flag = true;
        for (int i{ 0 }; i < n; ++i) {
            sum += vec[i];
            if(m < vec[i]) flag = false;
            if (sum > m) {
                cnt++;
                sum = vec[i];
            }
        }
        if (cnt <= k && flag == true) {
            r = m - 1;
            ans = min(ans, m);
        }
        else {
            l = m + 1;
        }
    }
    cout << ans;
}

