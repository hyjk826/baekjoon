// 2022-09-21
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
    int n, k, b;
    cin >> n >> k >> b;
    vi ch(n + 1, 1);
    for(int i{0}; i < b; ++i){
        int a;
        cin >> a;
        ch[a]--;
    }
    for(int i{1}; i <= n; ++i){
        ch[i] += ch[i - 1];
    }
    int ans{MAX};
    for(int i{0}; i + k <= n; ++i){
        ans = min(ans, k - (ch[i + k] - ch[i]));
    }
    cout << ans;
}
	

