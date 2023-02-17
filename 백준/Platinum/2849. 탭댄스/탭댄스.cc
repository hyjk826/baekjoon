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
    st() : l(-(ll)1e18), r(-(ll)1e18), mid(-(ll)1e18), all(0) {}
    st(ll _l, ll _r, ll _mid, ll _all) : l(_l), r(_r), mid(_mid), all(_all) {}
};


struct Seg{
    vector<st> seg;
    Seg(){
        seg.resize(4 * (int)2e5 + 10);
    }
    void merge(st& ret, st& left, st& right){
        ret.l = max(left.l, left.all + right.l);
        ret.r = max(right.r, left.r + right.all);
        ret.mid = max({left.mid, right.mid, left.r + right.l});
        ret.all = left.all + right.all;
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
        if(e < l || r < s) return {-(ll)1e18, -(ll)1e18, -(ll)1e18, 0};
        if(s <= l && r <= e) return seg[node];
        int m = (l + r) >> 1;
        st left = query(node * 2, l, m, s, e);
        st right = query(node * 2 + 1, m + 1, r, s, e);
        st ret;
        merge(ret, left, right);
        return ret;
    }
};


int main(){
	fastio;
    Seg s1, s2;
    int n, q;
    cin >> n >> q;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        if(i & 1) s1.update(1, 0, n - 1, i, -(int)1e7);
        else s1.update(1, 0, n - 1, i, 1);
    }
    for(int i{0}; i < n; ++i){
        if(i & 1) s2.update(1, 0, n - 1, i, 1);
        else s2.update(1, 0, n - 1, i, -(int)1e7);
    }
    while(q--){
        int a;
        cin >> a;
        a--;
        if(vec[a] == 0){
            vec[a] = 1;
            if(a & 1) {
                s1.update(1, 0, n - 1, a, 1);
                s2.update(1, 0, n - 1, a, -(int)1e7);
            }
            else{ 
                s1.update(1, 0, n - 1, a, -(int)1e7);
                s2.update(1, 0, n - 1, a, 1);
            }
        }
        else{
            vec[a] = 0;
            if(a & 1){
                s1.update(1, 0, n - 1, a, -(int)1e7);
                s2.update(1, 0, n - 1, a, 1);
            }
            else{
                s1.update(1, 0, n - 1, a, 1);
                s2.update(1, 0, n - 1, a, -(int)1e7);
            }
        }
        cout << max(s1.seg[1].mid, s2.seg[1].mid) << "\n";
    }
}
