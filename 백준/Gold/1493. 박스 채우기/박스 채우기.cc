// 2023-01-13
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

int main(){
	fastio;
    int x, y, z;
    cin >> x >> y >> z;
    int n;
    cin >> n;
    vi cnt(20);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a >> cnt[i];
    }
    int ans{0};
    function<void(int,int,int)> f = [&](int a, int b, int c){
        if(a == 0 || b == 0 || c == 0) return;
        int m = min({a, b, c});
        for(int i{19}; i >= 0; --i){
            if(cnt[i] == 0) continue;
            if((1 << i) <= m){
                int mn = min(cnt[i], m / (1 << i));
                int q = (1 << i);
                int w = (1 << i);
                int e = (1 << i);
                q *= mn;
                cnt[i] -= mn;
                ans += mn;
                int k = (1 << i);
                f(a, b, c - e);
                f(a - q, b, e);
                f(q, b - w, e);
                return;
            }
        }
        cout << -1; exit(0);
    };
    f(x, y, z);
    cout << ans;
}
