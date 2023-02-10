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
    vi num = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int n;
    cin >> n;
    n -= 4;
    for(int i{0}; i <= 99; ++i){
        for(int j{0}; j <= 99; ++j){
            if(i + j > 99) continue;
            int a{0}, b{0}, c{0};
            string s, t, r;
            s = to_string(i); t = to_string(j); r = to_string(i + j);
            if(s.size() == 1) s = "0" + s;
            if(t.size() == 1) t = "0" + t;
            if(r.size() == 1) r = "0" + r;
            a += num[s[0] - '0'] + num[s[1] - '0'];
            b += num[t[0] - '0'] + num[t[1] - '0'];
            c += num[r[0] - '0'] + num[r[1] - '0'];
            if(a + b + c == n){
                cout << s << "+" << t << "=" << r; return 0;
            }
        }
    }
    cout << "impossible";
}
