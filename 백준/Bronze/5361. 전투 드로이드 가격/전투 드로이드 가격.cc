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
        vi vec(5);
        for(int i{0}; i < 5; ++i) cin >> vec[i];
        double arr[] = {350.34, 230.90, 190.55, 125.30, 180.90};
        double ans{0};
        for(int i{0}; i < 5; ++i){
            ans += arr[i] * vec[i];
        }
        cout << fixed << setprecision(2);
        cout << "$";
        cout << ans << "\n";
    }
}

