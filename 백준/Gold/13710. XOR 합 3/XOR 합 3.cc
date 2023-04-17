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

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] ^= vec[i - 1];
    }   
    ll ans{0};
    for(int i{0}; i < 31; ++i){
        int zero{0}, one{0};
        for(int j{0}; j <= n; ++j){
            if((vec[j] >> i) & 1) one++;
            else zero++;
        }
        ans += 1LL * (1LL << i) * one * zero;
    }
    cout << ans;
}
