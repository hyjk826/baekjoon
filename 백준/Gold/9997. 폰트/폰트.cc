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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        for(int j{0}; j < (int)str.size(); ++j){
            vec[i] |= (1 << (str[j] - 'a'));
        }
    }
    int ans{0};
    function<void(int, int)> f = [&](int L, int mask){
        if(L == n){
            if(mask == (1 << 26) - 1) ans++;
            return;
        }
        f(L + 1, mask | (vec[L]));
        f(L + 1, mask);
    };
    f(0, 0);
    cout << ans;
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
