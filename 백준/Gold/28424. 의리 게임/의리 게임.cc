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
	int n, q;
    cin >> n >> q;
    vi p(n + 2);
    iota(p.begin(), p.end(), 0);
    vl sum(n + 2);
    vl vec(n + 2);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    function<int(int)> find = [&](int a){
        if(a == p[a]) return a;
        return p[a] = find(p[a]);
    };
    auto limit = vec;
    limit.back() = (ll)1e18;
    while(q--){
        int op, idx, x;
        cin >> op >> idx;
        if(op == 1){
            cin >> x;
            int a = find(idx);
            sum[a] += x;
            while(sum[a] > limit[a]){
                int b = find(a + 1);
                sum[b] += sum[a];
                limit[b] += limit[a];
                p[a] = b;
                a = b;
            }
        }
        else{
            int k = find(idx);
            if(k == idx) cout << vec[idx] - (limit[k] - sum[k]) << "\n";
            else cout << vec[idx] << "\n";
        }
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
