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
    vi ch(4);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        ch[a]++;
    }
    int ans{0};
    int a = min(ch[0], ch[3]);
    ans += 3 * a;
    ch[0] -= a; ch[3] -= a;
    int b = min(ch[1], ch[2]);
    ans += 3 * b;
    ch[1] -= b ; ch[2] -= b;
    ans += min(ch[0], ch[1]) * (0 ^ 1);
    ans += min(ch[0], ch[2]) * (0 ^ 2);
    ans += min(ch[3], ch[1]) * (3 ^ 1);
    ans += min(ch[3], ch[2]) * (3 ^ 2);
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
