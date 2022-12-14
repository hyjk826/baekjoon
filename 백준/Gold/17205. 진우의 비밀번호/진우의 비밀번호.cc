// 2022-12-14
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

ll f(int k){
    ll ret = 1;
    for(int i{0}; i < k; ++i){
        ret *= 26;
    }
    return ret;
}

int main() {
	fastio;
    int n;
    cin >> n;
    string str;
    cin >> str;
    ll ans{0};
    for(int i{0}; i < (int)str.size(); ++i){
        int a = str[i] - 'a';
        ll k{0};
        for(int j{0}; j <= n - i - 1; ++j){
            k += f(j);
        }
        k *= a;
        ans += k;
        ans++;
    }
    cout << ans;
}
	
