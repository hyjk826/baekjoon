// 2022-05-29
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int s, c;
    cin >> s >> c;
    vl vec(s);
    ll sum{0};
    for(int i{0}; i < s; ++i){
        cin >> vec[i];
        sum += vec[i];
    }
    ll l{1}, r{(ll)1e9};
    ll mx{0};
    while(l <= r){
        ll m{(l + r) / 2};
        ll cnt{0};
        for(int i{0}; i < s; ++i){
            cnt += vec[i] / m;
        }
        if(cnt >= c){
            mx = max(mx, m);
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << sum - c * mx;
}