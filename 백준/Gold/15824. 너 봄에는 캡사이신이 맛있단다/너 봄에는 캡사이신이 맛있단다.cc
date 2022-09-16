// 2022-09-15
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
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    ll ans{0};
    vl A((int)vec.size());
    A[0] = 1;
    for(int i{1}; i < (int)A.size(); ++i){
        A[i] = (A[i - 1] * 2) % MOD;
    }
    ll x{0}, y{0};
    for(int i{0}; i < n; ++i){
        x += vec[i] * A[i];
        x %= MOD;
    }
    reverse(A.begin(), A.end());
    for(int i{0}; i < n; ++i){
        y += vec[i] * A[i];
        y %= MOD;
    }
    cout << (x - y + MOD) % MOD;
}
	

