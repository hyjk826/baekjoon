// 2023-01-16
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
#define MOD 10007
using namespace std;

vector<vl> com(53, vl(53, -1));

ll f(ll a, ll b){
    if(com[a][b] != -1) return com[a][b];
    if(a == b || b == 0) return com[a][b] = 1;
    return com[a][b] = (f(a - 1, b - 1) + f(a - 1, b)) % MOD;
}

int main(){
	fastio;
    ll ans{0};
    int n;
    cin >> n;
    for(int i{1}; i <= 13 && n - 4 * i >= 0; ++i){
        if(i & 1){
            ans += f(13, i) * f(52 - 4 * i, n - 4 * i);
        }
        else ans -= f(13, i) * f(52 - 4 * i, n - 4 * i);
        ans = (ans + MOD * MOD) % MOD;
    }
    cout << ans;
}