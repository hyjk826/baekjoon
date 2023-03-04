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
unordered_map<ll, int> A, B;


void updateHashing(string& str, bool flag, bool remove){
    ll r1{0}, r2{0};
    int n = (int)str.size();
    for(int i{0}; i <= n - 1; ++i) {
        r1 = (r1 * p1 + str[i]) % mod1;
        r2 = (r2 * p2 + str[i]) % mod2;
        ll k = (r1 << 32 | r2);
        if(remove){
            if(flag == 0) A[k]--;
            else B[k]--;
        }
        else{
            if(flag == 0) A[k]++;
            else B[k]++;
        }
    }
}

int main(){
	fastio;
    int q;
    cin >> q;
    while(q--){
        string op, s, t;
        cin >> op;
        if(op == "add"){
            cin >> s >> t;
            if(s == "A") updateHashing(t, 0, 0);
            else {
                reverse(t.begin(), t.end());
                updateHashing(t, 1, 0);
            }
        }
        else if(op == "delete"){
            cin >> s >> t;
            if(s == "A") updateHashing(t, 0, 1);
            else {
                reverse(t.begin(), t.end());
                updateHashing(t, 1, 1);
            }
        }
        else if(op == "find"){
            cin >> s;
            ll ans{0};
            int n = (int)s.size();
            vl x(n), y(n);
            ll r1{0}, r2{0};
            for(int i{0}; i <= n - 1 ; ++i){
                r1 = (r1 * p1 + s[i]) % mod1;
                r2 = (r2 * p2 + s[i]) % mod2;
                x[i] = (r1 << 32 | r2);
            }
            r1 = r2 = 0;
            for(int i{n - 1}; i >= 0; --i){
                r1 = (r1 * p1 + s[i]) % mod1;
                r2 = (r2 * p2 + s[i]) % mod2;
                y[i] = (r1 << 32 | r2);
            }
            for(int i{0}; i < n - 1; ++i){
                if(A.count(x[i]) && B.count(y[i + 1])){
                    ans += 1LL * A[x[i]] * B[y[i + 1]];
                }
            }
            cout << ans << "\n";
        }
    }
}
