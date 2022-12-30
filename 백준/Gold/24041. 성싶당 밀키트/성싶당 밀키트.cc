// 2022-12-30
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
    int a, b, c;
};

int main(){
	fastio;
    int n, g, k;
    cin >> n >> g >> k;
    vector<st> vec(n);
    int cnt{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i].a >> vec[i].b >> vec[i].c;
        if(vec[i].c == 1) cnt++;
    }
    int a = min(cnt, k);
    ll l{0}, r{MAX};
    ll ans{0};
    while(l <= r){
        ll m{(l + r) >> 1};
        sort(vec.begin(), vec.end(), [&](st& x, st& y){
            if(x.c == y.c){
                return x.a * max(1LL, m - x.b) > y.a * max(1LL, m - y.b);
            }
            else return x.c > y.c;
        });
        ll sum{0};
        for(int i{a}; i < n; ++i){
            sum += vec[i].a * max(1LL, m - vec[i].b);
        }
        if(sum <= g){
            l = m + 1;
            ans = m;
        }
        else r = m - 1;
    }
    cout << ans;
}
