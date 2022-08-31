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
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    ll ans{0};
    ll sum{0};
    for(int i{0}; i < n; ++i){
        ans += 1LL * i * vec[i] - sum;
        sum += vec[i];
    }
    sum = 0;
    for(int i{n - 1}; i >= 0; --i){
        ans += sum - 1LL * (n - 1 - i) * vec[i];
        sum += vec[i];
    }
    cout << ans;
}

