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
    int l, r, idx;
};

const int sz = 3e4 + 10;
int n, q;
vector<st> query(sz);

struct st2{
    int mn, mx, num;
    st2() : mn(MAX), mx(-MAX), num(MAX){}
};

vector<st2> seg(sz * 4);
vl vec(sz);
vi cnt(sz);

void update(int node, int l, int r, int idx, int flag){
    if(l > idx || r < idx) return;
    if(l == r) {
        if(flag == 1){
            seg[node].mn = seg[node].mx = idx;
            seg[node].num = MAX;
        }
        else{
            seg[node].mn = seg[node].num = MAX;
            seg[node].mx = -MAX;
        }
    }
    else{
        int m = (l + r) >> 1;
        update(node * 2, l, m, idx, flag);
        update(node * 2 + 1, m + 1, r, idx, flag);            
        seg[node].mn = min(seg[node * 2].mn, seg[node * 2 + 1].mn);
        seg[node].mx = max(seg[node * 2].mx, seg[node * 2 + 1].mx);
        seg[node].num = min(seg[node * 2].num, seg[node * 2 + 1].num); 
        if(seg[node * 2 + 1].mn != MAX && seg[node * 2].mx != -MAX){
            seg[node].num = min(seg[node].num, seg[node * 2 + 1].mn - seg[node * 2].mx);
        }
    }
}

void Plus(int k){
    update(1, 1, n, k, 1);                                                                                                    
}

void Minus(int k){
    update(1, 1, n, k, 0);
}

int main() {
	fastio;	
    cin >> n >> q;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
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
    vi ans(q);
    for(int i{l}; i <= r; ++i){
        Plus(vec[i]);
    }
    ans[query[0].idx] = seg[1].num;
    for(int i{1}; i < q; ++i){
        while(l > query[i].l) Plus(vec[--l]);
        while(r < query[i].r) Plus(vec[++r]);
        while(l < query[i].l) Minus(vec[l++]);        
        while(r > query[i].r) Minus(vec[r--]);
        ans[query[i].idx] = seg[1].num;
    }
    for(auto& i : ans) cout << i << "\n";
}
	
