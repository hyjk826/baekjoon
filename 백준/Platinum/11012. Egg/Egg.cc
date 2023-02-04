
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

const int sz = 101010;
Node* root[sz];

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
        cur->v++;
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

ll query(Node* node, int l, int r, int s, int e){
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return node->v;
    int m = (l + r) >> 1;
    return query(node->l, l, m, s, e) + query(node->r, m + 1, r, s, e);
}

int main(){
	fastio;
    root[0] = new Node();
    init(root[0], 1, 100001);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<vi> Y(100010);
        for(int i{0}; i < n; ++i){
            int x, y;
            cin >> x >> y;
            x++; y++;
            Y[x].push_back(y);
        }
        for(int i{1}; i <= 100001; ++i){
            if(Y[i].empty()) root[i] = root[i - 1];
            else root[i] = new Node();
            for(auto& j : Y[i]){
                update(root[i - 1], root[i], 1, 100001, j, 1);
            }
        }
        ll ans{0};
        while(q--){
            int x1, y1, x2, y2;
            cin >> x1 >> x2 >> y1 >> y2;
            x1++; x2++; y1++; y2++;
            ans += query(root[x2], 1, 100001, y1, y2) - query(root[x1 - 1], 1, 100001, y1, y2);
        }
        cout << ans << "\n";
    }
}
