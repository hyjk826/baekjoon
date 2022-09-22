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
    int s, k;
    cin >> s >> k;
    vi vec(k, s / k);
    s %= k;
    for(int i{0}; i < s; ++i){
        vec[i]++;
    }
    ll ans{1};
    for(int i{0}; i < k; ++i){
        ans *= vec[i];
    }
    cout << ans;
}
	

