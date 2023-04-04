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

const int sz = 1e5 + 10;
ll pw1[sz], pw2[sz];
vector<vl> h1(10);
vector<vl> h2(10);

ll substr(int l, int r, int idx){
    ll r1 = h1[idx][l] - h1[idx][r + 1] * pw1[r - l + 1]; r1 %= mod1; if(r1 < 0) r1 += mod1;
    ll r2 = h2[idx][l] - h2[idx][r + 1] * pw2[r - l + 1]; r2 %= mod2; if(r2 < 0) r2 += mod2;
    return (r1 << 32 | r2);
}

int main(){
	fastio;
    int n;
    cin >> n;
    vs vec(n);
    int l{1}, r{MAX};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        r = min(r, (int)vec[i].size());
    }
    pw1[0] = pw2[0] = 1;
    for(int i{1}; i < sz; ++i){
        pw1[i] = pw1[i - 1] * p1 % mod1;
        pw2[i] = pw2[i - 1] * p2 % mod2;
    }
    for(int i{0}; i < n; ++i){
        h1[i].resize(vec[i].size() + 1);
        h2[i].resize(vec[i].size() + 1);
        for(int j{(int)vec[i].size() - 1}; j >= 0; --j){
            h1[i][j] = (h1[i][j + 1] * p1 + vec[i][j]) % mod1;
            h2[i][j] = (h2[i][j + 1] * p2 + vec[i][j]) % mod2;
        }
    }
    int ans{0};
    while(l <= r){
        int mid{(l + r) >> 1};
        bool ok = false;
        unordered_set<ll> st1;
        for(int j{0}; j + mid - 1 < (int)vec[0].size(); ++j){
            ll k = substr(j, j + mid - 1, 0);
            st1.insert(k);
        }
        for(int i{1}; i < n; ++i){
            unordered_set<ll> st2;
            for(int j{0}; j + mid - 1 < (int)vec[i].size(); ++j){
                ll k = substr(j, j + mid - 1, i);
                if(!st1.count(k)) continue;
                st2.insert(k);
            }
            swap(st1, st2);
        }        
        if(!st1.empty()){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans;
}
