// 2022-09-16
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;



int main() {
	fastio;
    ll n;
    cin >> n;
    int sz = (int)to_string(n).size();
    vl vec;
    for(int i{2}; i <= sz; ++i){
        ll k = stoll(string(i, '1'));
        bool flag = false;
        for(int j{0}; j < (int)vec.size(); ++j){
            flag |= (k % vec[j] == 0);
        }
        if(!flag) vec.push_back(k);
    }
    ll ans{0};
    int a = (int)vec.size();
    for(int i{1}; i < (1 << a); ++i){
        int cnt = __builtin_popcount(i);
        ll l{1};
        for(int j{0}; j < a; ++j){
            if((i >> j) & 1){
                int b = to_string(l).size();
                l *= vec[j];
                if(l > n || b + to_string(vec[j]).size() - 1 > sz){
                    l = n + 1;
                    break;
                }
            }
        }
        if(cnt & 1) ans += n / l;
        else ans -= n / l;
    }
    cout << ans;
}
	

