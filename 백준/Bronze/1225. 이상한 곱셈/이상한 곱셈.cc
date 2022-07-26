// 2022-07-26
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
    ll ans{0};
    string s, t;
    cin >> s >> t;
    for(int i{0}; i < (int)s.size(); ++i){
        for(int j{0}; j < (int)t.size(); ++j){
            ans += (s[i] - '0') * (t[j] - '0');
        }
    }
    cout << ans;
}

