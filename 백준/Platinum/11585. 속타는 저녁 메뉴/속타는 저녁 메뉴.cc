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

int rabin_karp(string& s, string t){
    int n = (int)s.size();
    int m = (int)t.size();
    ll x{0}, y{0}, power{1};
    int ret{0};
    for(int i{0}; i <= n - m; ++i){
        if(i == 0){
            for(int j{0}; j < m; ++j){
                x = (x + s[m - 1 - j] * power) % MOD;
                y = (y + t[m - 1 - j] * power) % MOD;
                if(j < m - 1) power = (power * 403) % MOD;
            }            
        }
        else{
            x = (403 * (x - s[i - 1] * power) + s[i + m - 1]) % MOD;
            if(x < 0) x += MOD;
        }
        if(x == y) ret++;
    }
    return ret;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
    int n;
    cin >> n;
    string s, t;
    for(int i{0}; i < n; ++i){
        char c;
        cin >> c;
        s += c;
    }
    for(int i{0}; i < n; ++i){
        char c;
        cin >> c;
        t += c;
    }
    for(int i{0}; i < n - 1; ++i){
        s += s[i];
    }
    int ret = rabin_karp(s, t);
    int g = gcd(ret, n);
    ret /= g; n /= g;
    cout << ret << "/" << n;
}
