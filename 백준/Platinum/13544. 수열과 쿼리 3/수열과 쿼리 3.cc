// 2022-07-29
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n;
vi vec(100001);
vector<vi> seg(400010);

void init(int node, int l, int r){
    if(l == r) seg[node].push_back(vec[l]);
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        seg[node].resize(r - l + 1);
        merge(seg[node * 2].begin(), seg[node * 2].end(), seg[node * 2 + 1].begin(), seg[node * 2 + 1].end(), seg[node].begin());
    }
}

int query(int node, int l, int r, int s, int e, int k){
    if(s > r || e < l) return 0;
    if(s <= l && r <= e){
        return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), k);
    }
    int m = (l + r) / 2;
    return query(node * 2, l, m, s, e, k) + query(node * 2 + 1, m + 1, r, s, e, k);
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    int q;
    cin >> q;
    int last = 0;
    while(q--){
        int s, e, k;
        cin >> s >> e >> k;
        s ^= last;
        e ^= last;
        k ^= last;
        int ans = query(1, 0, n - 1, s - 1, e - 1, k);
        cout << ans << "\n";
        last = ans;
    }
}

