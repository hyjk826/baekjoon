// 2022-12-15
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

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        unsigned long long a, b;
        string s, t;
        cin >> s >> t;
        bool m1, m2;
        m1 = m2 = false;
        if(s[0] == '-') m1 = true;
        if(t[0] == '-') m2 = true;
        string x, y;
        for(int i{0}; i < (int)s.size(); ++i){
            if(s[i] == '-' || s[i] == '.') continue;
            x += s[i];
        }
        for(int i{0}; i < (int)t.size(); ++i){
            if(t[i] == '-' || t[i]== '.') continue;
            y += t[i];
        }
        a = stoull(x);
        b = stoull(y);
        a *= b;
        if(m1 ^ m2) cout << "-";
        string ans = to_string(a);
        int k = (int)ans.size();
        for(int i{0}; i < 19 - k; ++i){
            ans = '0' + ans;
        }
        if(ans.size() == 19){
            for(int i{0}; i < (int)ans.size(); ++i){
                cout << ans[i];
                if(i == 0) cout << '.';
            }
        }
        else{
            for(int i{0}; i < (int)ans.size(); ++i){
                cout << ans[i];
                if(i == 1) cout << '.';
            }
        }
        cout << "\n";
    }
}
	
