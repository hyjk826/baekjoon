// 2022-11-01
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
#define MOD 100000007
using namespace std;

ll f(int n){
    ll ret{0};
    for(int i{1}; i <= n; ++i){
        if(i & 1) ret -= n / i;
        else ret += n / i;
    }
    return ret;
}

int main() {
	fastio;
	int s, t;
    cin >> s >> t;
    cout << f(t) - f(s - 1);
}
	

