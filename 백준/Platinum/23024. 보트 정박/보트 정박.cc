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

const int sz = 2e5 + 10;
vl maxSeg(sz * 4);
vl vec(sz);

void init(int node, int l, int r){
    if (l == r){
        maxSeg[node] = vec[l];
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
}

void update(int node, int l, int r, int idx, ll value){
    if(l > idx || r < idx) return;
    if(l == r){
        maxSeg[node] = value;
    }
    else{
        int m = (l + r) / 2;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
    }
}

ll query(int node, int l, int r, int s, int e){
    if (r < s || e < l)
        return -LLONG_MAX;
    if (s <= l && r <= e)
        return maxSeg[node];
    int m = (l + r) / 2;
    ll left = query(node * 2, l, m, s, e);
    ll right = query(node * 2 + 1, m + 1, r, s, e);
    return max(left, right);
}

int n, m;

void init2(){
    for(int i{0}; i <= 4 * n; ++i){
        maxSeg[i] = 0;
    }
}


void solve(){
    cin >> n >> m;
    init2();
    vl B(m + 1);
    for(int i{1}; i <= n; ++i) {
        cin >> vec[i];
    }
    init(1, 1, n);
    for(int i{1}; i <= m; ++i) {
        cin >> B[i];        
    }
    function<int(ll)> f = [&](ll x){
        int l{1}, r{n};
        int ret{-1};
        while(l <= r){
            int mid{(l + r) >> 1};
            if(query(1, 1, n, 1, mid) >= x){
                ret = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ret;
    };
    ll ans{0};
    for(int i{1}; i <= m; ++i){
        int k = f(B[i]);
        if(k == -1) continue;
        ans += 1LL * i * k;
        update(1, 1, n, k, 0);
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
