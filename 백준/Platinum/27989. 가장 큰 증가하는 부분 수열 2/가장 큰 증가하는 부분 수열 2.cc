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

struct Seg{
    vl maxSeg;
    Seg(int sz){
        maxSeg.resize(sz * 4);
    }
    void update(int node, int l, int r, int idx, ll value){
        if(l > idx || r < idx) return;
        if(l == r){
            maxSeg[node] = max(maxSeg[node], value);
        }
        else{
            int m = (l + r) >> 1;
            update(node << 1, l, m, idx, value);
            update(node << 1 | 1, m + 1, r, idx, value);
            maxSeg[node] = max(maxSeg[node << 1], maxSeg[node << 1 | 1]);
        }
    }

    ll query(int node, int l, int r, int s, int e){
        if (r < s || e < l)
            return 0;
        if (s <= l && r <= e)
            return maxSeg[node];
        int m = (l + r) >> 1;
        ll left = query(node << 1, l, m, s, e);
        ll right = query(node << 1 | 1, m + 1, r, s, e);
        return max(left, right);
    }
};
int main(){
	fastio;
	int n;
    cin >> n;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vl A = vec;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    Seg seg((int)A.size() + 10);
    ll ans{0};
    for(int i{0}; i < n; ++i){
        int idx = lower_bound(A.begin(), A.end(), vec[i]) - A.begin() + 1;
        ll mx = seg.query(1, 0, (int)A.size(), 0, idx - 1);
        ans = max(ans, mx + vec[i]);
        seg.update(1, 0, (int)A.size(), idx, mx + vec[i]);
    }
    cout << ans;
}
