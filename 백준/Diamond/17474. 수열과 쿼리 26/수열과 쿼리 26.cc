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

struct Node{
    ll mx, mx2, cntmx, sum;
};

const int sz = (int)1e6 + 10;
vl vec(sz);
vector<Node> seg(sz * 4);

Node merge(Node a, Node b){
    if(a.mx == b.mx) return {a.mx, max(a.mx2, b.mx2), a.cntmx + b.cntmx, a.sum + b.sum};
    if(a.mx > b.mx) swap(a, b);
    return {b.mx, max(a.mx, b.mx2), b.cntmx, a.sum + b.sum};
}

Node init(int node, int l, int r){
    if(l == r) return seg[node] = {vec[l], -MAX, 1, vec[l]};
    int m = (l + r) >> 1;
    return seg[node] = merge(init(node * 2, l, m), init(node * 2 + 1, m + 1, r));
}

void propogate(int node, int l, int r){
    if(l == r) return;
    for(auto& i : {node * 2, node * 2 + 1}){
        if(seg[node].mx < seg[i].mx){
            seg[i].sum -= seg[i].cntmx * (seg[i].mx - seg[node].mx);
            seg[i].mx = seg[node].mx;
        }
    }
}

void update(int node, int l, int r, int s, int e, ll val){
    propogate(node, l, r);
    if(e < l || r < s || seg[node].mx <= val) return;
    if(s <= l && r <= e && seg[node].mx2 < val){
        seg[node].sum -= seg[node].cntmx * (seg[node].mx - val);
        seg[node].mx = val;
        propogate(node, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(node * 2, l, m, s, e, val);
    update(node * 2 + 1, m + 1, r, s, e, val);
    seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
}

ll getMx(int node, int l, int r, int s, int e){
    propogate(node, l, r);
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return seg[node].mx;
    int m = (l + r) >> 1;
    return max(getMx(node * 2, l, m, s, e), getMx(node * 2 + 1, m + 1, r, s, e));
}

ll getSum(int node, int l, int r, int s, int e){
    propogate(node, l, r);
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return seg[node].sum;
    int m = (l + r) >> 1;
    return getSum(node * 2, l, m, s, e) + getSum(node * 2 + 1, m + 1, r, s, e);
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
        ll op, a, b, c;
        cin >> op;
        if(op == 1){
            cin >> a >> b >> c;
            update(1, 1, n, a, b, c );
        }
        else if(op == 2){
            cin >> a >> b;
            cout << getMx(1, 1, n, a, b) << "\n";
        }
        else{
            cin >> a >> b;
            cout << getSum(1, 1, n, a, b) << "\n";
        }
    }
}
