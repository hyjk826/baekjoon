// 2022-12-07
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

ll modpow(ll a, ll b){
    ll ans{1};
    while(b > 0){
        if(b % 2){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        b /= 2;
        a %= MOD;
    }
    return ans;
}

int main() {
	fastio;
	int n;
    cin >> n;
    string str;
    cin >> str;
    vi vec(3);
    ll ans{0};
    for(int i{n - 1}; i >= 0; --i){
        if(str[i] == 'K'){
            vec[2]++;
        }
        else if(str[i] == 'C'){
            vec[1] += vec[2];
            vec[1] %= MOD;
        }
        else if(str[i] == 'O'){
            vec[0] += vec[1];
            vec[0] %= MOD;
        }
        else if(str[i] == 'R'){
            ans += 1LL * modpow(2, i) * vec[0];
            ans %= MOD;
        }
    }
    cout << ans;
}
	
