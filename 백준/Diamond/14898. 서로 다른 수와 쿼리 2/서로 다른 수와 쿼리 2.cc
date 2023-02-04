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
    int v;
    Node* l, *r;
    Node(){
        l = r = NULL;
        v = 0;
    }
};

const int sz = 1000010;
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

ll query(Node* node, int l, int r, int s, int e){
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return node->v;
    int m = (l + r) >> 1;
    return query(node->l, l, m, s, e) + query(node->r, m + 1, r, s, e);
}

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n + 1);
    vi A;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        A.push_back(vec[i]);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vi pos(n, -1);
    for(int i{1}; i <= n; ++i){
        vec[i] = lower_bound(A.begin(), A.end(), vec[i]) - A.begin();
    }
    root[0] = new Node();
    root[0]->l = root[0]->r = root[0];
    for(int i{1}; i <= n; ++i){
        root[i] = new Node();
        update(root[i - 1], root[i], 1, n, i, 1);
        if(pos[vec[i]] != -1) {
            update(root[i - 1], root[i], 1, n, pos[vec[i]], -1);
        }
        pos[vec[i]] = i;
    }
    int q;
    cin >> q;
    int l{0};
    while(q--){
        int x, r;
        cin >> x >> r;
        l += x;
        int ans = query(root[r], 1, n, l, r);
        l = ans;
        cout << ans << "\n";
    }
}
