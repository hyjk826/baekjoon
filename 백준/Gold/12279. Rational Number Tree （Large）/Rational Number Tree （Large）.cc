// 2023-01-22
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
#define ll unsigned long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

pl f1(ll n){
    string s;
    while(n){
        s += char('0' + n % 2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    ll x{1}, y{1};
    for(int i{1}; i < (int)s.size(); ++i){
        if(s[i] == '0'){
            y += x;
        }
        else{
            x += y;
        }
    }
    return {x, y};
}

ll f2(ll a, ll b){
    string s;
    while(!(a == 1 && b == 1)){
        if(a < b) {
            b -= a;
            s += '0';
        }
        else{
            a -= b;
            s += '1';
        }
    }
    s += '1';
    ll ret{0};
    ll k{1};
    for(int i{0}; i < (int)s.size(); ++i){
        if(s[i] == '1') ret += k;
        k *= 2;
    }
    return ret;
}

void solve(){
    ll op, a, b;
    cin >> op;
    if(op == 1){
        cin >> a;
        auto ret = f1(a);
        cout << ret.first << " " << ret.second << "\n";
    }
    else{
        cin >> a >> b;
        cout << f2(a, b) << "\n";
    }
}

int main() {
	fastio;	
	int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        cout << "Case #" << T << ": ";
        solve();
    }
}
	
