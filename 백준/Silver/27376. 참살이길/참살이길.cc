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
    int n, k;
    cin >> n >> k;
    struct st{
        ll x, t, s;
    };
    if(k == 0){
        cout << n; return 0;
    }
    vector<st> vec(k);
    for(int i{0}; i < k; ++i){
        cin >> vec[i].x >> vec[i].t >> vec[i].s;
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        return a.x < b.x;
    }); 
    ll ans{0};
    for(int i{0}; i < k; ++i){
        if(i == 0) ans += vec[i].x;
        else ans += vec[i].x - vec[i - 1].x;
        ll a = (ans - vec[i].s) % (2 * vec[i].t);
        if(ans < vec[i].s){
            ans += vec[i].s - ans;
        } else if(a >= vec[i].t) ans += 1LL * 2 * vec[i].t - a;
    }
    ans += n - vec.back().x;
    cout << ans;
}
