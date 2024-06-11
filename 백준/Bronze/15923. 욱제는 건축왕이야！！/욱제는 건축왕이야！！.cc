#include <bits/stdc++.h>
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
	int n;
    cin >> n;
    vp vec(n);
    for(auto& i : vec) cin >> i.first >> i.second;
    int ans{0};
    for(int i{0}; i < n; ++i){
        ans += abs(vec[i].first - vec[(i + 1) % n].first) + abs(vec[i].second - vec[(i + 1) % n].second);
    }
    cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int T;
	T = 1;
	while(T--){
		solve();
	}
}