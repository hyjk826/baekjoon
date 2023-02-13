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
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a >> vec[i];
    }
    map<int, ll> mp;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;        
        int l = min(vec[a], vec[b]);
        int r = max(vec[a], vec[b]);
        mp[r + 1] -= c;
        mp[l] += c;
    }
    for(auto i{next(mp.begin())}; i != mp.end(); ++i){
        i->second += prev(i)->second;
    }
    ll ans{0};
    for(auto& i : mp){
        ans = max(ans, i.second);
    }
    cout << ans;
}
