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

const int sz = 5e5 + 10;
int arr[sz];

struct st{
    int mn, OR, AND, lazyOR, lazyAND;
    st() : mn(MAX), OR(0), AND(0), lazyOR(0), lazyAND((1 << 30) - 1){}
    st(int a, int b, int c, int d, int e){
        mn = a; OR = b; AND = c; lazyOR = d; lazyAND = e;
    }
};

st seg[sz * 4];

void merge(int node, int l, int r){
    seg[node].mn = min(seg[l].mn, seg[r].mn);
    seg[node].OR = seg[l].OR | seg[r].OR;
    seg[node].AND = seg[l].AND & seg[r].AND;
}

void init(int node, int l, int r){
    if(l == r) {
        seg[node] = {arr[l], arr[l], arr[l], 0, (1 << 30) - 1};
    }
    else{
        int mid{(l + r) >> 1};
        init(node << 1, l, mid);
        init(node << 1 | 1, mid + 1, r);
        merge(node, node << 1, node << 1 | 1);
    }
}

void propogate(int node, int l, int r){
    if(seg[node].lazyOR == 0 && seg[node].lazyAND == (1 << 30) - 1) return;
    seg[node].mn &= seg[node].lazyAND; seg[node].AND &= seg[node].lazyAND; seg[node].OR &= seg[node].lazyAND;
    seg[node].mn |= seg[node].lazyOR; seg[node].AND |= seg[node].lazyOR; seg[node].OR |= seg[node].lazyOR;
    if(l ^ r){
        seg[node << 1].lazyAND &= seg[node].lazyAND; seg[node << 1].lazyOR &= seg[node].lazyAND; seg[node << 1].lazyOR |= seg[node].lazyOR;
        seg[node << 1 | 1].lazyAND &= seg[node].lazyAND; seg[node << 1 | 1].lazyOR &= seg[node].lazyAND; seg[node << 1 | 1].lazyOR |= seg[node].lazyOR;
    }
    seg[node].lazyOR = 0; seg[node].lazyAND = (1 << 30) - 1;
}

void update(int node, int l, int r, int s, int e, int x, bool flag){
    propogate(node, l, r);
    if(r < s || l > e) return;
    if(s <= l && r <= e){
        bool ok = true;
        for(int i{0}; i < 30; ++i){
            if(flag && !((x >> i) & 1)) continue;
            if(!flag && ((x >> i) & 1)) continue;
            ok &= (((seg[node].OR >> i) & 1) == ((seg[node].AND >> i) & 1));
            if(!ok) break;
        }
        if(ok){
            if(flag) seg[node].lazyOR |= x;
            else{
                seg[node].lazyAND &= x;
                seg[node].lazyOR &= x;
            }            
            propogate(node, l, r);
            return;
        }
    }
    int mid{(l + r) >> 1};
    update(node << 1, l, mid, s, e, x, flag);
    update(node << 1 | 1, mid + 1, r, s, e, x, flag);
    merge(node, node << 1, node << 1 | 1);
}

int query(int node, int l, int r, int s, int e){
    propogate(node, l, r);
    if(r < s || l > e) return MAX;
    if(s <= l && r <= e) return seg[node].mn;
    int mid{(l + r) >> 1};
    return min(query(node << 1, l, mid, s, e), query(node << 1 | 1, mid + 1, r, s, e));
}

int main(){
	fastio;
	int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> arr[i];
    }
    init(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--){
        char op;
        int a, b, c;
        cin >> op;
        if(op == '&'){
            cin >> a >> b >> c; a--; b--;
            update(1, 0, n - 1, a, b, c, 0);
        }
        else if(op == '|'){
            cin >> a >> b >> c; a--; b--;
            update(1, 0, n - 1, a, b, c, 1);
        }
        else{
            cin >> a >> b; a--; b--;
            cout << query(1, 0, n - 1, a, b) << "\n";
        }
    }
}
