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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi A(n), B(m);
        for(int i{0}; i < n; ++i){
            cin >> A[i];
        }
        for(int i{0}; i < m; ++i){
            cin >> B[i];
        }
        sort(B.begin(), B.end());
        int ans{0};
        for(int i{0}; i < n; ++i){
            ans += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        }
        cout << ans << "\n";
    }
}

