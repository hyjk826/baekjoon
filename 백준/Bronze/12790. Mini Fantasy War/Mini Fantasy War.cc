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
        vi vec(4);
        for(int i{0}; i < 2; ++i){
            for(int j{0}; j < 4; ++j){
                int a;
                cin >> a;
                vec[j] += a;
            }
        }
        ll ans{0};
        ans += max(1, vec[0]);
        ans += 5 * max(1, vec[1]);
        ans += 2 * max(0, vec[2]);
        ans += 2 * vec[3];
        cout << ans << "\n";
    }
}

