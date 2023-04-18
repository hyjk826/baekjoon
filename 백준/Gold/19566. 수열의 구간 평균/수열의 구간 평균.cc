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
    vl vec(n + 1);
    map<int, map<int,int>> mp;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    if(k == 0){
        map<ll, int> temp;
        for(int i{0}; i <= n; ++i){
            temp[vec[i]]++;
        }
        ll ans{0};
        for(auto& i : temp){
            ans += 1LL * i.second * (i.second - 1) / 2;
        }
        cout << ans; return 0;
    }
    for(int i{0}; i <= n; ++i){
        mp[vec[i] % k][vec[i] / k - i]++;
    }
    ll ans{0};
    for(auto& i : mp){
        for(auto& j : i.second){
            ans += 1LL * j.second * (j.second - 1) / 2;
        }
    }
    cout << ans;
}
