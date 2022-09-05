// 2022-09-05
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
    while(1){
        int n;
        cin >> n;
        if(!n) break;
        int ans{0};
        for(int i{1}; i <= n; ++i){
            ans += (n - i + 1) * (n - i + 1);
        }
        cout << ans << "\n";
    }
}
	

