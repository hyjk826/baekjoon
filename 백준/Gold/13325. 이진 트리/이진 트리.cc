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
    vi w(1 << (n + 1));
    ll ans{0};
    for(int i{2}; i < (1 << (n + 1)); ++i){
        cin >> w[i];
        ans += w[i];
    }
    vi mx(1 << (n + 1));
    function<void(int)> dfs = [&](int cur){
        int k{0};
        for(int i{0}; i <= 1; ++i){
            if(2 * cur + i >= (1 << (n + 1))) continue;
            dfs(2 * cur + i);
            k = max(k, mx[2 * cur + i]);
        }
        mx[cur] = w[cur] + k;
    };
    dfs(1);
    for(int i{1}; i < (1 << (n + 1)); ++i){
        if(2 * i >= (1 << (n + 1))) continue;
        ans += abs(mx[2 * i] - mx[2 * i + 1]);
    }
    cout << ans;
}
