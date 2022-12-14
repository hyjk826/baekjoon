// 2022-12-14
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

set<string> st;

void f(string str, int l, int r){
    if(l > r) return;
    if(l == r) {
        st.insert(str);
    }
    else{
        int sz = r - l + 1;
        if(sz & 1){
            sz /= 2;
            string t = str;
            t = str;
            reverse(t.begin() + l, t.begin() + l + sz);
            f(t, l + sz, r);
            t = str;
            reverse(t.begin() + l + sz, t.begin() + r + 1);
            f(t, l, l + sz - 1);
            sz++;
            t = str;
            reverse(t.begin() + l, t.begin() + l + sz);
            f(t, l + sz, r);
            t = str;
            reverse(t.begin() + l + sz, t.begin() + r + 1);
            f(t, l, l + sz - 1);
        }
        else{
            sz /= 2;
            string t = str;
            reverse(t.begin() + l, t.begin() + l + sz);
            f(t, l + sz, r);
            t = str;
            reverse(t.begin() + l + sz, t.begin() + r + 1);
            f(t, l, l + sz - 1);
        }
    }
};
int main() {
	fastio;
    vi ch(26);
    int n;
    cin >> n;
    int cnt{0};
    for(int i{0}; i < n; ++i){
        char c; int a;
        cin >> c >> a;
        cnt += a;
        ch[c - 'a'] += a; 
    }
    string str;
    cin >> str;
    for(int i{0}; i <= (int)str.size() - cnt; ++i){
        string s = str.substr(i, cnt);
        bool ok = true;
        vi ch2(26);
        for(int j{0}; j < (int)s.size(); ++j){
            ch2[s[j] - 'a']++;
        }
        for(int j{0}; j < 26; ++j){
            ok &= (ch[j] == ch2[j]);
        }
        if(!ok) continue;
        f(s, 0, (int)s.size() - 1);
    }
    cout << st.size();
}
	
