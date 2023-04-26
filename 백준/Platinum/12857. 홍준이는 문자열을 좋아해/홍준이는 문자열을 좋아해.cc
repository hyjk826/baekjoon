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

const int sz = 5e4 + 10;
ll ha1[sz], pw1[sz];
ll ha2[sz], pw2[sz];

void power(){
    pw1[0] = pw2[0] = 1;
    for(int i{1}; i < sz; ++i){
        pw1[i] = pw1[i - 1] * p1 % mod1;
        pw2[i] = pw2[i - 1] * p2 % mod2;
    }
}

void hashing(string& str){
    int n = (int)str.size();
    for(int i{n - 1}; i >= 0; --i) ha1[i] = (ha1[i + 1] * p1 + str[i]) % mod1;
    for(int i{n - 1}; i >= 0; --i) ha2[i] = (ha2[i + 1] * p2 + str[i]) % mod2;
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
    hashing(str);
    unordered_map<ll, vi> mp;
    for(int i{1}; i <= 4; ++i){
        for(int j{0}; j + i - 1 <= (int)str.size() - 1; ++j){
            ll k = substr(j, j + i - 1);
            mp[k].push_back(j);
        }
    }
    for(auto& i : mp){
        sort(i.second.begin(), i.second.end());
    }
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        ll a = oneHashing(s);
        ll b = oneHashing(t);
        if(!mp.count(a) || !mp.count(b)) cout << -1 << "\n";
        else{
            int ans{MAX};
            auto& A = mp[a];
            auto& B = mp[b];
            int i{0}, j{0};
            for(int i{0}; i < (int)A.size(); ++i){
                while(j < (int)B.size() && B[j] < A[i]) j++;
                if(j < (int)B.size()) ans = min(ans, max(A[i] + (int)s.size() - 1, B[j] + (int)t.size() - 1) - A[i] + 1);
                if(j) ans = min(ans, max(A[i] + (int)s.size() - 1, B[j - 1] + (int)t.size() - 1) - B[j - 1] + 1);
            }
            cout << ans << "\n";
        }
    }

}
