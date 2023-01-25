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
    int l, r, idx;
};

int n, q;
int sum{0};
const int sz = 1e5 + 10;
vector<st> query(sz);
vi A;

vl maxSeg(sz * 4);
vi vec;

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        maxSeg[node] += value;
    }
    else{
        int m = (l + r) / 2;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
    }
}

void Plus(int k){
    update(1, 1, n, k, A[k]);
}

void Minus(int k){
    update(1, 1, n, k, -A[k]);
}


int main() {
	fastio;	
    cin >> n >> q;
    vec.resize(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    A = vec;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i{1}; i <= n; ++i){
        vec[i] = lower_bound(A.begin(), A.end(), vec[i]) - A.begin();
    }
    for(int i{0}; i < q; ++i){
        cin >> query[i].l >> query[i].r;
        query[i].idx = i;
    }
    int sq = sqrt(n);
    sort(query.begin(), query.begin() + q, [&](st& a, st& b){
        if(a.l / sq == b.l / sq) return a.r < b.r;
        else return a.l / sq < b.l / sq;
    });
    int l = query[0].l;
    int r = query[0].r;
    vl ans(q);
    for(int i{l}; i <= r; ++i){
        Plus(vec[i]);
    }
    ans[query[0].idx] = maxSeg[1];
    for(int i{1}; i < q; ++i){
        while(l > query[i].l) Plus(vec[--l]);
        while(r < query[i].r) Plus(vec[++r]);
        while(l < query[i].l) Minus(vec[l++]);        
        while(r > query[i].r) Minus(vec[r--]);
        ans[query[i].idx] = maxSeg[1];
    }
    for(auto& i : ans) cout << i << "\n";
}
	
