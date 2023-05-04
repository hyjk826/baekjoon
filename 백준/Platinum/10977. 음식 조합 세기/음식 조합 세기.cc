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

const int sz = 2e6 + 10;
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

int main(){
	fastio;
    power();
	int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vi vec(m);
        for(int i{0}; i < m; ++i){
            cin >> vec[i];
        }
        if(m == 1){
            cout << n << "\n"; continue;
        }
        vi A;
        for(int i{1}; i < m; ++i){
            A.push_back(vec[i] - vec[i - 1]);
        }
        A.push_back(vec[0] - vec[m - 1] + n);
        for(int i{0}; i < m; ++i){
            A.push_back(A[i]);
        }
        hashing(A);
        bool ok = false;
        for(int i{1}; i < m; ++i){
            if(substr(0, m - 1) == substr(i, i + m - 1)){
                ok = true;
                cout << vec[i] - vec[0] << "\n"; break;
            }
        }
        if(!ok) cout << n << "\n";
    }
}
