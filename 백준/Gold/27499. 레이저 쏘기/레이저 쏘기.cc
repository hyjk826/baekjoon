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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    for(int i{1}; i < k; ++i){
        for(int j{0}; j < n; ++j){
            if(i & 1) vec.push_back({m - vec[j].first + i * m, vec[j].second});
            else vec.push_back({vec[j].first + i * m, vec[j].second});
        }
    }
    map<pi,int> mp;
    for(auto& i : vec){
        int g = gcd(i.first, i.second);
        mp[{i.first / g, i.second / g}]++;
    }
    int ans{0};
    for(auto& i : mp) ans = max(ans, i.second);
    cout << ans;
}
