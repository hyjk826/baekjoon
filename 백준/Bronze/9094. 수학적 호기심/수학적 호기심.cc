// 2022-08-15
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
        int ans{0};
        for(int i{1}; i < n - 1; ++i){
            for(int j{i + 1}; j < n; ++j){
                if((i * i + j * j + m) % (i * j) == 0) ans++;
            }
        }
        cout << ans << "\n";
    }
}