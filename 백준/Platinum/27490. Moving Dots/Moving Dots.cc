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
    vi two(3001);
    two[0] = 1;
    for(int i{1}; i <= 3000; ++i){
        two[i] = two[i - 1] * 2;
        two[i] %= MOD;
    }
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            int a = lower_bound(vec.begin(), vec.end(), 2 * vec[i] - vec[j]) - vec.begin();
            int b = vec.end() - lower_bound(vec.begin(), vec.end(), 2 * vec[j] - vec[i]);
            ans += two[a + b];
            ans %= MOD;
        }
    }
    cout << ans;
}
