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
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i) cin >> vec[i];
    vec.push_back(0);
    int cnt{0};
    int ans{0};
    for(int i{1}; i <= n + 1; ++i){
        if(vec[i]) cnt++;
        else{
            ans = max(ans, cnt);
            cnt = 0;
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
