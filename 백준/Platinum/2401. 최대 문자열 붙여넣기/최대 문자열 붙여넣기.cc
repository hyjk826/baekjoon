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

const int sz = 1e5 + 10;
ll ha1[sz], pw1[sz];
ll ha2[sz], pw2[sz];

void hashing(string& str){
    int n = (int)str.size();
    for(int i{n - 1}; i >= 0; --i) ha1[i] = (ha1[i + 1] * p1 + str[i]) % mod1;    
    for(int i{n - 1}; i >= 0; --i) ha2[i] = (ha2[i + 1] * p2 + str[i]) % mod2;
    
}

void power(){
    pw1[0] = pw2[0] = 1;
    for(int i{1}; i < sz; ++i) pw1[i] = pw1[i - 1] * p1 % mod1;
    for(int i{1}; i < sz; ++i) pw2[i] = pw2[i - 1] * p2 % mod2;
}

ll substr(int l, int r){
    ll r1 = ha1[l] - ha1[r + 1] * pw1[r - l + 1]; r1 %= mod1; if(r1 < 0) r1 += mod1;
    ll r2 = ha2[l] - ha2[r + 1] * pw2[r - l + 1]; r2 %= mod2; if(r2 < 0) r2 += mod2;
    return (r1 << 32 | r2);
}

ll oneHashing(string& str){
    ll r1{0}, r2{0};
    int n = (int)str.size();
    for(int i{n - 1}; i >= 0; --i) r1 = (r1 * p1 + str[i]) % mod1;
    for(int i{n - 1}; i >= 0; --i) r2 = (r2 * p2 + str[i]) % mod2;
    return (r1 << 32 | r2);
}

int main(){
	fastio;
    power();
    string str;
    cin >> str;
    int n;
    cin >> n;
    vpl A;
    for(int i{0}; i < n; ++i){
        string s;
        cin >> s;
        ll k = oneHashing(s);
        A.push_back({s.size(), k});
    }
    hashing(str);
    vi dp((int)str.size(), -1);
    function<int(int)> f = [&](int a){
        if(a >= (int)str.size()) return 0;
        if(dp[a] != -1) return dp[a];
        dp[a] = 0;
        dp[a] = max(dp[a], f(a + 1));
        for(int i{0}; i < n; ++i){
            if(a + A[i].first - 1 >= (int)str.size()) continue;
            if(substr(a, a + A[i].first - 1) == A[i].second){
                dp[a] = max(dp[a], (int)A[i].first + f(a + A[i].first));
            }
        }
        return dp[a];
    };
    cout << f(0);
}
