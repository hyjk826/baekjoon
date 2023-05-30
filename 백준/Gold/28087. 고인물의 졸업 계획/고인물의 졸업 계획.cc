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

void solve(){
    int n, k;
    cin >> n >> k;
    vp vec;
    for(int i{0}; i < k; ++i){
        int a;
        cin >> a;
        if(n <= a && a <= 2 * n){
            cout << 1 << "\n" << i + 1 << "\n"; return;
        }
        if(a > 2 * n) continue;
        vec.push_back({a, i + 1});
    }
    int sum{0};
    vi ans;
    for(auto& i : vec){
        sum += i.first;
        ans.push_back(i.second);
        if(sum >= n) break;
    }
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << "\n";
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
