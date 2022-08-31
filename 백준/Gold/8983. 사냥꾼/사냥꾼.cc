// 2022-08-31
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
    int m, n, d;
    cin >> m >> n >> d;
    vi vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        int l = a - d + b;
        int r = a + d - b;
        if(l > r) continue;
        int k = upper_bound(vec.begin(), vec.end(), r) - upper_bound(vec.begin(), vec.end(), l - 1);
        if(k > 0) ans++;
    }
    cout << ans;
}

