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
    ll v;
    Node* l, *r;
    Node(){
        l = r = NULL;
        v = 0;
    }
};

Node* root[101010];
vi vec(101010);

void init(Node* node, int l, int r){
    if(l == r){
        node->v = 0;
        return;
    }
    int m = (l + r) >> 1;
    node->l = new Node();
    node->r = new Node();
    init(node->l, l, m);
    init(node->r, m + 1, r);
    node->v = node->l->v + node->r->v;
}

void update(Node* prev, Node* cur, int l, int r, int idx, int value){
    if(l == r){
        cur->v += value;
        return;
    }
    int m = (l + r) >> 1;
    if(cur->l == NULL) cur->l = prev->l;
    if(cur->r == NULL) cur->r = prev->r;
    if(idx <= m){
        if(cur->l == prev->l){
            cur->l = new Node();
            cur->l->v = prev->l->v;
        }
        update(prev->l, cur->l, l, m, idx, value);
    }
    else{
        if(cur->r == prev->r){
            cur->r = new Node();
            cur->r->v = prev->r->v;
        }
        update(prev->r, cur->r, m + 1, r, idx, value);
    }
    cur->v = cur->l->v + cur->r->v;
}

// Kth
int query(Node* ls, Node* rs, int l, int r, int k){
    if(l == r) return l;
    int diff = rs->l->v - ls->l->v;
    int m = (l + r) >> 1;
    if(k <= diff) return query(ls->l, rs->l, l, m, k);
    else return query(ls->r, rs->r, m + 1, r, k - diff);
}

int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    root[0] = new Node();
    init(root[0], 0, n);
    vi vec(n + 1);
    int mx{0};
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        root[i] = new Node();
        update(root[i - 1], root[i], 1, n, vec[i], 1);
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        int l{1}, r{n};
        int ans{1};
        while(l <= r){
            int mid{(l + r) / 2};
            if(b - a + 1 - mid + 1 >= 1 && query(root[a - 1], root[b], 1, n, b - a + 1 - mid + 1) >= mid){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << "\n";
    }
}
