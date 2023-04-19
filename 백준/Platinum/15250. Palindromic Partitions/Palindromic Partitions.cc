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

const ll p1 = 179, mod1 = 1e9 - 63;
const ll p2 = 917, mod2 = 1e9 + 7;

const int sz = 1e6 + 10;
ll ha1[sz], pw1[sz];
ll ha2[sz], pw2[sz];

void hashing(string& str){
    int n = (int)str.size();
    for(int i{n - 1}; i >= 0; --i) ha1[i] = (ha1[i + 1] * p1 + str[i]) % mod1;
    for(int i{n - 1}; i >= 0; --i) ha2[i] = (ha2[i + 1] * p2 + str[i]) % mod2;
}

ll substr(int l, int r){
    ll r1 = ha1[l] - ha1[r + 1] * pw1[r - l + 1]; r1 %= mod1; if(r1 < 0) r1 += mod1;
    ll r2 = ha2[l] - ha2[r + 1] * pw2[r - l + 1]; r2 %= mod2; if(r2 < 0) r2 += mod2;
    return (r1 << 32 | r2);
}

int main(){
	fastio;
    pw1[0] = pw2[0] = 1;
    for(int i{1}; i <= (int)1e6; ++i){
        pw1[i] = pw1[i - 1] * p1 % mod1;
        pw2[i] = pw2[i - 1] * p2 % mod2;
    }
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        hashing(str);
        int l{0}, r{(int)str.size() - 1};
        int ans{0};
        while(1){
            bool flag = false;
            for(int i{0}; l + i < r - i; ++i){
                if(substr(l, l + i) == substr(r - i, r)){
                    l = l + i + 1;
                    r = r - i - 1;
                    flag = true; break;
                }
            }
            if(!flag){
                ans++; break;
            }
            ans += 2;
            if(l > r) break;
        }
        cout << ans << "\n";
    }
}
