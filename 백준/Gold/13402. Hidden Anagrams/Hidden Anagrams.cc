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

ll oneHashing(vi& vec){
    ll r1{0}, r2{0};
    int n = (int)vec.size();
    for(int i{n - 1}; i >= 0; --i) r1 = (r1 * p1 + vec[i]) % mod1;
    for(int i{n - 1}; i >= 0; --i) r2 = (r2 * p2 + vec[i]) % mod2;
    return (r1 << 32 | r2);
}

int main(){
	fastio;
    string s, t;
    cin >> s >> t;
    int a = min((int)s.size(), (int)t.size());
    int l{1}, r{a};
    int ans{0};
    for(int x{a}; x >= 1; --x){
        vi cnt(26);
        set<ll> st;
        bool ok = false;
        for(int i{0}; i < x - 1; ++i){
            cnt[s[i] - 'a']++;
        }
        for(int i{x - 1}; i < (int)s.size(); ++i){
            cnt[s[i] - 'a']++;
            if(i != x - 1) cnt[s[i - x] - 'a']--; 
            st.insert(oneHashing(cnt));
        }
        for(int i{0}; i < 26; ++i){
            cnt[i] = 0;
        }
        for(int i{0}; i < x - 1; ++i){
            cnt[t[i] - 'a']++;
        }
        for(int i{x - 1}; i < (int)t.size(); ++i){
            cnt[t[i] - 'a']++;
            if(i != x - 1) cnt[t[i - x] - 'a']--; 
            if(st.count(oneHashing(cnt))){
                ok = true; break;
            }
        }
        if(ok){
            cout << x; return 0;
        }
    }
    cout << 0;
}
