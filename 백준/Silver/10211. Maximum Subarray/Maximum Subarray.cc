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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
            vec[i] += vec[i - 1];
        }
        vi post = vec;
        for(int i{n - 1}; i >= 0; --i){
            post[i] = max(post[i], post[i + 1]);
        }
        int ans{-MAX};
        for(int i{0}; i < n; ++i){
            ans = max(ans, post[i + 1] - vec[i]);
        }
        cout << ans << "\n";
    }
}

