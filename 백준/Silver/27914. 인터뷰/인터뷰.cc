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
    int n, k, q;
    cin >> n >> k >> q;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        if(k == vec[i]) vec[i] = 0;
        else vec[i] = 1;
    }
    for(int i{1}; i <= n; ++i){
        if(vec[i] == 0) continue;
        vec[i] += vec[i - 1];
    }
    vi ans(n + 1);
    for(int i{1}; i <= n; ++i){
        if(vec[i] == 0) ans[i] += ans[i - 1];
        else{
            ans[i] -= vec[i - 1] * (vec[i - 1] + 1) / 2;
            ans[i] += vec[i] * (vec[i] + 1) / 2;
            ans[i] += ans[i - 1];
        }
    }
    while(q--){
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
