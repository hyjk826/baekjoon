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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    multiset<pi> ms;
    for(int i{0}; i < n; ++i){
        auto it = ms.lower_bound({vec[i], 0});
        if(it == ms.begin() || (--it)->first != vec[i] - 1) ms.insert({vec[i], 1});
        else{
            int cnt = it->second;
            ms.erase(it);
            ms.insert({vec[i], cnt + 1});
        }
    }
    ll ans{0};
    for(auto& i : ms){
        ans += 1LL * i.first * i.second;
    }
    cout << ans;
}
