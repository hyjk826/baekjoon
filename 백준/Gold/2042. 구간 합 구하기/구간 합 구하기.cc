#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define vi vector<int> 
#define pi pair<int, int> 
#define vp vector<pi> 
#define MAX 2147000000
#define ll long long 
using namespace std; 

const int sz = (int)1e6 + 10;
ll arr[sz];
ll seg[sz * 4];


void init(int node, int l, int r){
    if(l == r) seg[node] = arr[l];
    else{
        int mid{(l + r) >> 1};
        init(node << 1, l, mid);
        init(node << 1 | 1, mid + 1, r);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

void update(int node, int l, int r, int idx, ll value){
    if(idx < l || r < idx) return;
    if(l == r){
        seg[node] = arr[idx] = value;
    }
    else{
        int mid{(l + r) >> 1};
        update(node << 1, l, mid, idx, value);
        update(node << 1 | 1, mid + 1, r, idx, value);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

ll sum(int node, int l, int r, int s, int e){
    if(r < s || e < l) return 0LL;
    if(s <= l && r <= e) return seg[node];
    int mid{(l + r) >> 1};
    ll left = sum(node << 1, l, mid, s, e);
    ll right = sum(node << 1 | 1, mid + 1, r, s, e);
    return left + right;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i{1}; i <= n; ++i){
        cin >> arr[i];
    }
    init(1, 1, n);

    for(int i{0}; i < m + k; ++i){
        ll op, a, b;
        cin >> op >> a >> b;
        if(op == 1){
            update(1, 1, n, a, b);
        }
        else{
            cout << sum(1, 1, n, a, b) << "\n";
            
        }
    }
}