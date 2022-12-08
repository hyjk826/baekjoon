// 2022-12-08
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

struct st{
    ll a, b, c;
};

int main() {
	fastio;
	ll n, atk;
    cin >> n >> atk;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
    }
    ll l{0}, r{(ll)1e17};
    ll ans{LLONG_MAX};
    while(l + 1 < r){
        ll mid{(l + r) / 2};
        ll h = mid;
        ll at = atk;
        for(int i{0}; i < n; ++i){
            if(vec[i].a == 1){
                ll a = (vec[i].c + at - 1) / at;
                ll b = (h + vec[i].b - 1) / vec[i].b;
                if(a <= b){
                    h -= vec[i].b * (a - 1);
                }
                else{
                    h = 0;
                    break;
                }
            }
            else{
                at += vec[i].b;
                h = min(mid, h + vec[i].c); 
            }
        }
        if(h >= 1){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    cout << r;
}
	
