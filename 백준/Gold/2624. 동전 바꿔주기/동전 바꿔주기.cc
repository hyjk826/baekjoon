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
    vi ans(t + 1);
    ans[0] = 1;
    int k;
    cin >> k;
    for(int i{0}; i < k; ++i){
        int p, n;
        cin >> p >> n;
        for(int j{t}; j >= 0; --j){
            if(ans[j] == 0) continue;
            for(int k{j + p}, l{0}; k <= t && l < n; k += p, ++l){
                ans[k] += ans[j];
            }
        }
    }
    cout << ans.back();
}

