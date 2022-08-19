// 2022-08-19
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
    int n, m, q;
    cin >> n >> m >> q;
    int ans{0};
    int l{1}, r{m};
    while(q--){
        int a;
        cin >> a;
        if(l <= a && a <= r) continue;
        if(a > r){
            ans += a - r;
            r = a;
            l = r - m + 1;
        }
        else{
            ans += l - a;
            l = a;
            r = a + m - 1;
        }
    }
    cout << ans;
}