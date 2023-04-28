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
    int n, m;
    cin >> n >> m;
    map<ll, vl> mp;
    for(int i{0}; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        mp[b].push_back(a);
    }
    ll sum{0};
    ll ans{LLONG_MAX};
    for(auto& i : mp){
        sort(i.second.rbegin(), i.second.rend());
        for(int j{0}; j < (int)i.second.size(); ++j){
            sum += i.second[j];
            if(sum >= m){
                ans = min(ans, i.first * (j + 1));
            }
        }
    }
    if(ans == LLONG_MAX) ans = -1;
    cout << ans;
}
