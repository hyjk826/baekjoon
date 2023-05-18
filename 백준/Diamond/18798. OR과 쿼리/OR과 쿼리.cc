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

const int sz = 3e5 + 10;

vp seg(sz * 4);
vi vec(sz);
int n, k;

void init(int node, int l, int r){
    if(l == r) {
        seg[node].first = vec[l];
        if(vec[l] == k) {
            seg[node].second = 1;
        }
    }
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        seg[node].first = (seg[node << 1].first & seg[node << 1 | 1].first);
        seg[node].second = seg[node << 1].second + seg[node << 1 | 1].second;
    }
}

void update(int node, int l, int r, int s, int e, int value){
    if(r < s || l > e) return;
    if((value | seg[node].first) == seg[node].first) return;
    if(l == r) {
        if(seg[node].first == k) seg[node].second--;
        seg[node].first |= value;
        if(seg[node].first == k) seg[node].second++;
    }
    else{
        int m = (l + r) >> 1;
        update(node * 2, l, m, s, e, value);
        update(node * 2 + 1, m + 1, r, s, e, value);            
        seg[node].first = (seg[node << 1].first & seg[node << 1 | 1].first);
        seg[node].second = seg[node << 1].second + seg[node << 1 | 1].second;
    }
}

int query(int node, int l, int r, int s, int e){
    if(r < s || l > e) return 0;
    if(s <= l && r <= e) return seg[node].second;
    int mid{(l + r) >> 1};
    return query(node << 1, l, mid, s, e) + query(node << 1 | 1, mid + 1, r, s, e);
}


int main(){
	fastio;
    cin >> n >> k;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--){
        int op, l, r, c;
        cin >> op;
        if(op == 1){
            cin >> l >> r >> c;
            l--; r--;
            update(1, 0, n - 1, l, r, c);
        }
        else{
            cin >> l >> r;
            l--; r--;
            cout << query(1, 0, n - 1, l, r) << "\n";
        }
    }
}
