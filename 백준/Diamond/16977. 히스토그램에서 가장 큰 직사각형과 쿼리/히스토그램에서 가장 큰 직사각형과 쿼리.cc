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

vector<st> seg(400010);

void merge(st& ret, st& left, st& right){
    ret.l = max(left.l, left.all + right.l);
    ret.r = max(right.r, left.r + right.all);
    ret.mid = max({left.mid, right.mid, left.r + right.l});
    ret.all = left.all + right.all;
}

void init(int node, int l, int r){
    if(l == r){
        seg[node] = {-MAX, -MAX, -MAX, -MAX};
        return;
    }
    int m = (l + r) / 2;
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
    int m = (l + r) / 2;
    update(node * 2, l, m, idx, value);
    update(node * 2 + 1, m + 1, r, idx, value);
    merge(seg[node], seg[node * 2], seg[node * 2 + 1]);
}

st Query(int node, int l, int r, int s, int e){
    if(e < l || r < s) return {-MAX, -MAX, -MAX, 0};
    if(s <= l && r <= e) return seg[node];
    int m = (l + r) / 2;
    st left = Query(node * 2, l, m, s, e);
    st right = Query(node * 2 + 1, m + 1, r, s, e);
    st ret;
    merge(ret, left, right);
    return ret;
}

struct Q{
    int l, r, w;
};

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n + 1);
    vi A;
    vp B;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        B.push_back({vec[i], i});
        A.push_back(vec[i]);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    sort(B.begin(), B.end(), [&](pi& x, pi& y){
        return x.first > y.first;
    });
    reverse(A.begin(), A.end());
    int q;
    cin >> q;
    vector<Q> query(q);
    for(int i{0}; i < q; ++i){
        cin >> query[i].l >> query[i].r >> query[i].w;
    }
    vi l(q), r(q, (int)A.size() - 1);
    vi ans(q, -1);
    while(1){
        init(1, 1, n);
        bool ok = false;
        vector<vi> mid((int)A.size());
        for(int i{0}; i < q; ++i){
            if(l[i] <= r[i]){
                ok = true;
                mid[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!ok) break;
        int idx{0};
        for(int i{0}; i < (int)A.size(); ++i){
            while(idx < (int)B.size() && B[idx].first >= A[i]){
                update(1, 1, n, B[idx].second, 1);
                idx++;
            }
            for(auto& j : mid[i]){
                int a  = query[j].l;
                int b  = query[j].r;
                if(Query(1, 1, n, a, b).mid >= query[j].w){
                    ans[j] = A[i];
                    r[j] = i - 1;
                }
                else l[j] = i + 1;
            }
        }
        
    }
    for(auto& i : ans) cout << i << "\n";
}
