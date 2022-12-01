// 2022-12-01
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
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;


int main() {
	fastio;
	int n;
    cin >> n;
    vi ans(n + 1);
    int cnt{2};
    ans[1] = 1;
    for(ll i{2}; i <= n; ++i){
        if(ans[i]) continue;
        ans[i] = cnt;
        for(ll j{i * i}; j <= n; j += i){
            ans[j] = cnt;
        }
        cnt++;
    }
    cout << cnt - 1 << "\n";
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << " ";
    }
}
	
