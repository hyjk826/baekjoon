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

ll oneHashing(string& str){
    ll r1{0}, r2{0};
    int n = (int)str.size();
    for(int i{0}; i <= n - 1; ++i) {
        r1 = (r1 * p1 + str[i]) % mod1;
        r2 = (r2 * p2 + str[i]) % mod2;
    }
    return (r1 << 32 | r2);
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    unordered_map<ll, int> A, B;
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        ll ret = oneHashing(str);
        A[ret]++;
    }
    for(int i{0}; i < m; ++i){
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        ll ret = oneHashing(str);
        B[ret]++;
    }
    int q;
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        int sz = (int)str.size();
        vl x(sz), y(sz);
        ll r1{0}, r2{0};
        for(int i{0}; i < sz; ++i){
            r1 = (r1 * p1 + str[i]) % mod1;
            r2 = (r2 * p2 + str[i]) % mod2;
            x[i] = (r1 << 32 | r2);
        }
        r1 = r2 = 0;
        for(int i{sz - 1}; i >= 0; --i){
            r1 = (r1 * p1 + str[i]) % mod1;
            r2 = (r2 * p2 + str[i]) % mod2;
            y[i] = (r1 << 32 | r2);
        }
        bool ok = false;
        for(int i{0}; i < sz - 1; ++i){
            if(A.count(x[i]) && B.count(y[i + 1])){
                ok = true; break;
            }
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }

}
