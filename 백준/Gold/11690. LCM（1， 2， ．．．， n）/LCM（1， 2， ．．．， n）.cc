// 2022-11-30
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

vc ch((int)1e8 + 1, '0');


int main() {
	fastio;
	for(ll i{2}; i <= (int)1e8; ++i){
        if(ch[i] == '0'){
            for(ll j{i * i}; j <= (int)1e8; j += i){
                ch[j] = '1';
            }
        }
    }
    ll ans{1};
    ll n;
    cin >> n;
    for(int i{2}; i <= n; ++i){
        if(ch[i] == '1') continue;
        ll k{1};
        while(k * i<= n){
            k *= i;
            ans *= i;
            ans %= (1LL << 32);
        }
    }
    cout << ans;
}
	
