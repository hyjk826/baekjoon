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
	int n, m;
    cin >> n >> m;
    vi id(n * m + 1);
    vi level(n * m + 1);
    int mx{0};
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            int a;
            cin >> a;
            if(a == -1) continue;
            mx = max(mx, a);
            ans += i * 20;
            id[a] = j;
            level[a] = i;
        }
    }
    vi p(n);
    for(int i{1}; i <= mx; ++i){
        int idx = id[i];
        idx = (idx + p[level[i]] + m) % m;
        if(idx <= m - idx){
            ans += idx * 5;
            p[level[i]] = (p[level[i]] - idx + m) % m;
        }
        else{
            ans += (m - idx) * 5;
            p[level[i]] = (p[level[i]] + (m - idx) + m) % m;
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
