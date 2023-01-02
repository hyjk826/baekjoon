// 2023-01-02
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
#define MOD 1000000007LL
using namespace std;

const int sz = (int)1e6;

vl phi(sz + 1);

void ETF(){
    for(int i{1}; i <= sz; ++i){
        phi[i] = i;
    }
    for(int i{2}; i <= sz; ++i){
        if(phi[i] == i){
            phi[i] = i - 1;
            for(int j{2 * i}; j <= sz; j += i){
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
    }
}

int main(){
	fastio;
    ETF();
    vl A(sz + 1);
    for(int i{1}; i <= sz; ++i){
        for(int j{i}; j <= sz; j += i){
            A[j] += (i * phi[i]);
        }
    }
    ll n;
    cin >> n;
    ll ans{0};
    for(int i{2}; i <= n; ++i){
        ans += (A[i] + 1) * i / 2;
        ans %= MOD;
    }
    ans = (ans - (n * (n + 1) / 2 - 1) + MOD * MOD) % MOD;
    cout << ans;
}
