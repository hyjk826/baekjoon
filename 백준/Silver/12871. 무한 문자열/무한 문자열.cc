// 2022-08-23
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	fastio;
    string s, t;
    cin >> s >> t;
    int g = gcd(s.size(), t.size());
    string a, b;
    for(int i{0}; i < (int)t.size() / g; ++i) a += s;
    for(int i{0}; i < (int)s.size() / g; ++i) b += t;
    if(a == b) cout << 1;
    else cout << 0;
}

