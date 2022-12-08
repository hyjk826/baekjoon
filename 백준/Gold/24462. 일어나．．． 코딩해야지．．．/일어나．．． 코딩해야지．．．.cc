// 2022-12-08
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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}


int main() {
	fastio;
    ll n, d;
    cin >> n >> d;
    vpl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    vpl ans;
    ll mx{0};
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            ll a = d / vec[i].second + 1;
            if(vec[i].first >= 1) a -= (vec[i].first - 1) / vec[i].second + 1;
            a += d / vec[j].second + 1;
            if(vec[j].first >= 1) a -= (vec[j].first - 1) / vec[j].second + 1;
            ll lcm = vec[i].second / gcd(vec[i].second, vec[j].second) * vec[j].second;
            a -= d / lcm + 1;
            if(max(vec[i].first, vec[j].first) >= 1){
                a += ((max(vec[i].first, vec[j].first) - 1) / lcm) + 1;      
            }
            if(a > mx){
                ans.clear();
                ans.push_back({i + 1, j + 1});
                mx = a;
            }
            else if(a == mx){
                ans.push_back({i + 1, j + 1});
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].first << " " << ans[0].second << "\n";
    cout << mx;
}
	
