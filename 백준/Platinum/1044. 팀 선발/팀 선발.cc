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

bool comp(const pl& x, const pl& y){
    if(x.first == y.first) return x.second < y.second;
    else return x.first < y.first;
}

void solve(){
	int n;
    cin >> n;
    vl A(n), B(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }
    int h = n / 2;
    vector<vpl> g(h + 1);
    map<ll, map<ll, ll> > mp;
    for(int i{0}; i < (1 << h); ++i){
        ll sum{0};
        for(int j{0}; j < h; ++j){
            if((i >> j) & 1){
                sum -= B[n - 1 - j];
            }
            else sum += A[n - 1 - j];
        }
        int s = __builtin_popcount(i);
        if(mp[s].count(sum)) mp[s][sum] = min(mp[s][sum], (ll)i);
        else mp[s][sum] = i;
    }
    for(auto& i : mp){
        for(auto& j : i.second){
            g[i.first].push_back({j.first, j.second});
        }
    }
    for(int i{0}; i <= h; ++i){
        sort(g[i].begin(), g[i].end());
    }
    pi ans = {MAX, MAX};
    ll mn{LLONG_MAX};
    for(int i{0}; i < (1 << h); ++i){
        ll sum{0};
        for(int j{0}; j < h; ++j){
            if((i >> j) & 1){
                sum -= B[h - 1 - j];
            }
            else sum += A[h - 1 - j];
        }
        int need = h - __builtin_popcount(i);
        int idx = lower_bound(g[need].begin(), g[need].end(), make_pair(-sum, -1), comp) - g[need].begin();
        function<void()> f = [&](){
            ll k = g[need][idx].first + sum;
            if(abs(k) < mn){
               mn = abs(k);
               ans =  {i, g[need][idx].second};
            }
            else if(abs(k) == mn){
                if(!comp(ans, {i, g[need][idx].second})){
                    ans = {i, g[need][idx].second};
                }
            }
        };  
        if(idx != g[need].size()) f();
        if(idx != 0){
            idx--; f();
        }
    }
    vi res(n, 1);
    for(int i{0}; i < h; ++i){
        if((ans.first >> i) & 1) res[h - 1 - i] = 2;
        if((ans.second >> i) & 1) res[n - 1 - i] = 2;
    }
    for(auto& i : res) cout << i << " ";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
