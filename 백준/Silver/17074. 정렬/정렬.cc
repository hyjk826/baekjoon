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
    vi vec(n + 2);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vec[0] = -MAX;
    vec.back() = MAX;
    vi pre(n + 2, 1), post(n + 2, 1);
    for(int i{1}; i <= n + 1; ++i){
        pre[i] &= (pre[i - 1] & (vec[i - 1] <= vec[i]));
    }
    for(int i{n}; i >= 0; --i){
        post[i] &= (post[i + 1] & (vec[i] <= vec[i + 1]));
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        if(pre[i - 1] == 1 && post[i + 1] == 1 && vec[i - 1] <= vec[i + 1]) ans++;
    }
    cout << ans;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
