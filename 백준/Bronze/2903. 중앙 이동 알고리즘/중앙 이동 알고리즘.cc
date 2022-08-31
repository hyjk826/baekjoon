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
    vl ans(n + 1);
    ans[0] = 2;
    for(int i{1}; i <= n; ++i){
        ans[i] = ans[i - 1] + (1 << (i - 1));
    }
    cout << ans[n] * ans[n];
}