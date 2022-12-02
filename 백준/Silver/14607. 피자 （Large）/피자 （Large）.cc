// 2022-12-02
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

map<int, ll> mp;

ll f(int n){
    if(mp.count(n)) return mp[n];
    if(n == 1) return mp[n] = 0;
    if(n & 1){
        return mp[n] = 1LL * n / 2 * (n / 2 + 1) + f(n / 2) + f(n / 2 + 1);
    }
    else return mp[n] = 1LL * n / 2 * (n / 2) + f(n / 2) * 2;
}


int main() {
	fastio;
	int n;
    cin >> n;
    cout << f(n);
}
	
