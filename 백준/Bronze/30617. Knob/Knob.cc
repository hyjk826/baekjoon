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
	int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        if(vec[i].first != 0 && vec[i].first == vec[i].second) {
            ans++;
        }
        if(i){
            if(vec[i].first != 0 && vec[i].first == vec[i - 1].first) ans++;
            if(vec[i].second != 0 && vec[i].second == vec[i - 1].second) ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
