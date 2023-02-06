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
    int m, p, r;
};

int main(){
	fastio;
    int n, t;
    cin >> n >> t;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].m;
    }
    for(int i{0}; i < n; ++i){
        cin >> vec[i].p;
    }
    for(int i{0}; i < n; ++i){
        cin >> vec[i].r;
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return 1LL * x.r * y.p < 1LL * y.r * x.p;
    });
    vector<vl> dp(n, vl(t + 1, -1));
    function<ll(int,int)> f = [&](int L, int tt){
        if(L == n) return 0LL;
        if(dp[L][tt] != -1) return dp[L][tt];
        ll& ret = dp[L][tt];
        ret = 0;
        ret = max(ret, f(L + 1, tt));
        if(tt + vec[L].r <= t){
            ret = max(ret, f(L + 1, tt + vec[L].r) + vec[L].m - 1LL * (tt + vec[L].r) * vec[L].p);
        }
        return ret;
    };
    cout << f(0, 0);
}
