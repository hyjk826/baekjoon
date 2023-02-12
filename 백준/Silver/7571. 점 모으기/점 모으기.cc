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
    vp vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    ll ans{0};
    sort(vec.begin(), vec.end());
    for(int i{0}; i < m; ++i){
        ans += abs(vec[i].first - vec[m / 2].first);
    }
    sort(vec.begin(), vec.end(), [&](pi& x, pi& y){
        return x.second < y.second;
    });
    for(int i{0}; i < m; ++i){
        ans += abs(vec[i].second - vec[m / 2].second);
    }
    cout << ans;
}
