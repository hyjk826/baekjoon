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

const int sz = 8e6 + 10;
ll ha1[sz], pw1[sz];
ll ha2[sz], pw2[sz];

void power(){
    pw1[0] = pw2[0] = 1;
    for(int i{1}; i < sz; ++i){
        pw1[i] = pw1[i - 1] * p1 % mod1;
        pw2[i] = pw2[i - 1] * p2 % mod2;
    }
}

void hashing(vi& vec){
    int n = (int)vec.size();
    for(int i{n - 1}; i >= 0; --i) ha1[i] = (ha1[i + 1] * p1 + vec[i]) % mod1;
    for(int i{n - 1}; i >= 0; --i) ha2[i] = (ha2[i + 1] * p2 + vec[i]) % mod2;
}

ll substr(int l, int r){
    ll r1 = ha1[l] - ha1[r + 1] * pw1[r - l + 1]; r1 %= mod1; if(r1 < 0) r1 += mod1;
    ll r2 = ha2[l] - ha2[r + 1] * pw2[r - l + 1]; r2 %= mod2; if(r2 < 0) r2 += mod2;
    return (r1 << 32 | r2);
}

bool cmp(int x, int y){

}

int main(){
    power();
	fastio;
	int n;
    cin >> n;
    vi vec(n);
    for(int i{n - 1}; i >= 0; --i){
        cin >> vec[i];
    }
    for(int i{0}; i < n; ++i){
        vec.push_back(vec[i]);
    }
    hashing(vec);
    function<bool(int,int)> f = [&](int x, int y){
        int l{0}, r{n - 1};
        int ans{-1};
        while(l <= r){
            int mid{(l + r) >> 1};
            if(substr(x, x + mid) != substr(y, y + mid)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return vec[x + ans] < vec[y + ans];
    };
    int mn{1};
    for(int i{2}; i < n; ++i){
        if(f(i, mn)){
            mn = i;
        }
    }
    for(int i{0}; i < n; ++i){
        cout << vec[mn + i] << " ";
    }
}
