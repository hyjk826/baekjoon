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
    int n, x0, a, b;
    cin >> n >> x0 >> a >> b;
    int m;
    cin >> m;
    vi A(m);
    for(int i{0}; i < m; ++i){
        cin >> A[i];
        A[i]++;
    }
    sort(A.begin(), A.end());
    vi l(m), r(m, (int)1e9 + 6);
    ll ans{0};
    vi rs(m);
    while(1){
        bool ok = false;
        ll x = x0;
        vi cnt(m);
        vi mid(m);
        for(int i{0}; i < m; ++i){
            mid[i] = (l[i] + r[i]) >> 1;
        }
        for(int i{0}; i < n; ++i){
            int idx = lower_bound(mid.begin(), mid.end(), x) - mid.begin();
            if(idx < m) cnt[idx]++;
            x = (x * a + b) % MOD;
        }
        for(int i{0}; i < m; ++i){
            if(i) cnt[i] += cnt[i - 1];
            if(cnt[i] >= A[i]){                
                rs[i] = mid[i];
                r[i] = mid[i] - 1;
            }
            else l[i] = mid[i] + 1;
            if(l[i] <= r[i]){
                ok = true;
            }
        }
        if(!ok) break;
    }
    for(auto& i : rs){
        ans += i;
    }
    cout << ans;
}
