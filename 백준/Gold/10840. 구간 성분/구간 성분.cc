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

ll oneHashing(vi& vec) {
    ll r1{ 0 }, r2{ 0 };
    int n = (int)vec.size();
    for (int i{ n - 1 }; i >= 0; --i) r1 = (r1 * p1 + vec[i]) % mod1;
    for (int i{ n - 1 }; i >= 0; --i) r2 = (r2 * p2 + vec[i]) % mod2;
    return (r1 << 32 | r2);
}

int main() {
    fastio;
    string s, t;
    cin >> s >> t;
    for (int i{ min((int)s.size(), (int)t.size()) }; i >= 1; --i) {
        vi cnt(26);
        unordered_set<ll> st;
        for (int j{ 0 }; j < i - 1; ++j) {
            cnt[s[j] - 'a']++;
        }
        for (int j{ i - 1 }; j < (int)s.size(); ++j) {
            cnt[s[j] - 'a']++;
            if (j - i >= 0) cnt[s[j - i] - 'a']--;
            st.insert(oneHashing(cnt));
        }
        for (int j{ 0 }; j < 26; ++j) cnt[j] = 0;
        for (int j{ 0 }; j < i - 1; ++j) {
            cnt[t[j] - 'a']++;
        }
        for (int j{ i - 1 }; j < (int)t.size(); ++j) {
            cnt[t[j] - 'a']++;
            if (j - i >= 0) cnt[t[j - i] - 'a']--;
            if (st.count(oneHashing(cnt))) {
                cout << i; return 0;
            }
        }
    }
    cout << 0;
}
