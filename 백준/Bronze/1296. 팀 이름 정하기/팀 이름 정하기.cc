// 2022-09-21
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
    string s;
    cin >> s;
    int l = count(s.begin(), s.end(), 'L');
    int o = count(s.begin(), s.end(), 'O');
    int v = count(s.begin(), s.end(), 'V');
    int e = count(s.begin(), s.end(), 'E');
    int n;
    cin >> n;
    vs vec(n);
    string ans;
    ll mx{-1};
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        int a = count(str.begin(), str.end(), 'L');
        int b = count(str.begin(), str.end(), 'O');
        int c = count(str.begin(), str.end(), 'V');
        int d = count(str.begin(), str.end(), 'E');
        l += a;
        o += b;
        v += c;
        e += d;
        ll k = 1LL * (l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e);
        k %= 100;
        if(mx < k){
            mx = k;
            ans = str;
        }
        else if(mx == k){
            if(ans > str){
                ans = str;
            }
        }

        l -= a;
        o -= b;
        v -= c;
        e -= d;
    }
    cout << ans;
}
	

