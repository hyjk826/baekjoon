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
    int n, m, k;
    cin >> n >> m >> k;
    vs vec(k);
    for(auto& i : vec) cin >> i;
    string str;
    cin >> str;
    int l = m - 2; 
    int r = m - 1;
    while(l >= 0 && vec[str.back() - 'A'][l] == 'R') l--;
    ll ans = r - l;
    str.pop_back();
    for(int i{0}; i < n - 1; ++i){
        int idx = str.back() - 'A';
        str.pop_back();
        while(r > l && vec[idx][r] == 'R') r--;
        if(r == l) break;
        while(l >= 0 && vec[idx][l] == 'R') l--;
        ans += r - l;
    }
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
