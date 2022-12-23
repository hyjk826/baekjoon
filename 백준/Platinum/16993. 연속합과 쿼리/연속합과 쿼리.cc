// 2022-12-23
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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

struct st{
    int l, r, mid, all;
};

vector<st> seg(400010);
vi vec(100010);

void init(int node, int l, int r){
    if(l == r){
        seg[node] = {vec[l], vec[l], vec[l], vec[l]};
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    st& left = seg[node * 2];
    st& right = seg[node * 2 + 1];
    seg[node].l = max(left.l, left.all + right.l);
    seg[node].r = max(right.r, left.r + right.all);
    seg[node].mid = max(max(left.mid, right.mid), left.r + right.l);
    seg[node].all = left.all + right.all;
}



void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r) {
        seg[node] = {value, value, value, value};
        return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, idx, value);
    update(node * 2 + 1, m + 1, r, idx, value);
    st& left = seg[node * 2];
    st& right = seg[node * 2 + 1];
    seg[node].l = max(left.l, left.all + right.l);
    seg[node].r = max(right.r, left.r + right.all);
    seg[node].mid = max(max(left.mid, right.mid), left.r + right.l);
    seg[node].all = left.all + right.all;
}

st query(int node, int l, int r, int s, int e){
    if(e < l || r < s) return {-MAX, -MAX, -MAX, 0};
    if(s <= l && r <= e) return seg[node];
    int m = (l + r) / 2;
    st left = query(node * 2, l, m, s, e);
    st right = query(node * 2 + 1, m + 1, r, s, e);
    st ret;
    ret.l = max(left.l, left.all + right.l);
    ret.r = max(right.r, left.r + right.all);
    ret.mid = max(max(left.mid, right.mid), left.r + right.l);
    ret.all = left.all + right.all;
    return ret;
}

int main(){
    fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    int q;
    cin >> q;
    for(int i{0}; i < q; ++i){
        int a, b;
        cin >> a >> b;
        cout << query(1, 0, n - 1, a - 1, b - 1).mid << "\n";
    }
}
