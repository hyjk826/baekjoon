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

struct st{
    ll l, r, mid, all;
    st() : l(-MAX), r(-MAX), mid(-MAX), all(0) {}
    st(int _l, int _r, int _mid, int _all) : l(_l), r(_r), mid(_mid), all(_all) {}
};


const int sz = (int)1e5 + 10;
vector<st> seg(sz * 4);
vi vec(sz);

void merge(st& ret, st& left, st& right){
    ret.l = max(left.l, left.all + right.l);
    ret.r = max(right.r, left.r + right.all);
    ret.mid = max({left.mid, right.mid, left.r + right.l});
    ret.all = left.all + right.all;
}

void init(int node, int l, int r){
    if(l == r){
        seg[node] = {vec[l], vec[l], vec[l], vec[l]};
        return;
    }
    int m = (l + r) >> 1;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    merge(seg[node], seg[node * 2], seg[node * 2 + 1]);
}

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r) {
        seg[node] = {value, value, value, value};
        return;
    }
    int m = (l + r) >> 1;
    update(node * 2, l, m, idx, value);
    update(node * 2 + 1, m + 1, r, idx, value);
    merge(seg[node], seg[node * 2], seg[node * 2 + 1]);
}

st query(int node, int l, int r, int s, int e){
    if(e < l || r < s) return {-MAX, -MAX, -MAX, 0};
    if(s <= l && r <= e) return seg[node];
    int m = (l + r) >> 1;
    st left = query(node * 2, l, m, s, e);
    st right = query(node * 2 + 1, m + 1, r, s, e);
    st ret;
    merge(ret, left, right);
    return ret;
}

int main(){
	fastio;
    int n;
    cin >> n;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    init(1, 1, n);
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x2 > y1){
            auto l = query(1, 1, n, x1, y1);
            auto m = query(1, 1, n, y1 + 1, x2 - 1);
            auto r = query(1, 1, n, x2, y2);
            cout << l.r + m.all + r.l << "\n";
        }
        else{
            auto l = query(1, 1, n, x1, x2 - 1);
            auto m = query(1, 1, n, x2, y1);
            auto r = query(1, 1, n, y1 + 1, y2);
            ll ans{-LLONG_MAX};
            ans = max(ans, l.r + m.l);
            ans = max(ans, m.mid);
            ans = max(ans, m.r + r.l);
            ans = max(ans, l.r + m.all + r.l);
            cout << ans << "\n";
        }
    }
}
