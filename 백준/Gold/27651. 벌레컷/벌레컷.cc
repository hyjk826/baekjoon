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
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    ll ans{0};
    for(int i{2}; i < n; ++i){
        ll b = vec.back() - vec[i];
        ll mn = min(b - 1, vec[i] - b - 1);
        if(mn <= 0) continue;
        ans += upper_bound(vec.begin(), vec.end(), mn) - vec.begin() - 1;
    }
    cout << ans;
}
