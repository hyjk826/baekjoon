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
    int ans{1};
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int cur{vec[0] + k};
    for(int i{1}; i < n; ++i){
        if(cur < vec[i]){
            ans++;
            cur = vec[i] + k;
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
