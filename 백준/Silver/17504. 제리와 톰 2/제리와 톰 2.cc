// 2022-08-16
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

int n;

pl dp(int k, vl& vec){
    if(k == n - 1) return {1, vec[k]};
    pl a = dp(k + 1, vec);
    return {a.second, vec[k] * a.second + a.first};
}

int main() {
	fastio;
    cin >> n;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    pl a = dp(0, vec);
    cout << a.second - a.first << " " << a.second;
}

