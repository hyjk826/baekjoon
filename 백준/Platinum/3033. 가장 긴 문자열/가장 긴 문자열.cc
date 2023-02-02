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

int main(){
	fastio;
    int n;
    cin >> n;
    string str;
    cin >> str;
    int l{0}, r{n};
    int mod = 1e5;
    int ans{0};
    while(l <= r){
        int mid{(l + r) / 2};
        ll x{0}, y{0}, power{1};
        vector<vi> g(mod);
        bool ok = false;
        for(int i{0}; i <= n - mid; ++i){
            if(i == 0){
                for(int j{0}; j < mid; ++j){
                    x = (x + str[mid - 1 - j] * power) % mod;
                    if(j < mid - 1) power = (power * 403) % mod;
                }
            }
            else {
                x = (403 * (x - str[i - 1] * power) + str[i + mid - 1]) % mod;
                if(x < 0) x += mod;
            }
            for(auto& j : g[x]){
                bool ok2 = true;
                for(int k{0}; k < mid; ++k){
                    if(str[i + k] != str[j + k]){
                        ok2 = false;
                        break;
                    }
                }
                if(ok2){
                    ok = true;
                    break;
                }
            }
            if(ok) break;
            else g[x].push_back(i);
        }
        if(ok){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}
