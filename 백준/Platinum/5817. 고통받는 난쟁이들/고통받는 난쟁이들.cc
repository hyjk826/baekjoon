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

int n, q;
const int sz = 2e5 + 10;
vp minMaxSeg(sz * 4);
vi vec(sz);
vi idx(sz);

void init(int node, int l, int r){
    if (l == r) minMaxSeg[node] = {vec[l], vec[r]};
    else{
        int m = (l + r) >> 1;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        minMaxSeg[node].first = min(minMaxSeg[node * 2].first, minMaxSeg[node * 2 + 1].first);
        minMaxSeg[node].second = max(minMaxSeg[node * 2].second, minMaxSeg[node * 2 + 1].second);
    }
}

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        minMaxSeg[node] = {value, value};
    }
    else{
        int m = (l + r) >> 1;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        minMaxSeg[node].first = min(minMaxSeg[node * 2].first, minMaxSeg[node * 2 + 1].first);
        minMaxSeg[node].second = max(minMaxSeg[node * 2].second, minMaxSeg[node * 2 + 1].second);
    }
}

pi query(int node, int l, int r, int s, int e){
    if (r < s || e < l) return {MAX, -MAX};
    if (s <= l && r <= e) return minMaxSeg[node];
    int m = (l + r) >> 1;
    pi left = query(node * 2, l, m, s, e);
    pi right = query(node * 2 + 1, m + 1, r, s, e);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main(){
	fastio;
    cin >> n >> q;
    vi A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
        vec[A[i]] = i;
    }    
    init(1, 1, n);
    while(q--){
        int op, a, b;
        cin >> op >> a >> b;        
        if(op == 1){
            a--; b--;
            int c1 = A[a]; int c2 = A[b];
            update(1, 1, n, c2, a); 
            update(1, 1, n, c1, b);
            vec[c2] = a; vec[c1] = b;
            swap(A[a], A[b]);
        }
        else{
            auto ret = query(1, 1, n, a, b);
            if(ret.second - ret.first == b - a) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
