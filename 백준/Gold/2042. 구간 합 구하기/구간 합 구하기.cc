// 2022-09-14
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vl seg(4000001);
vl vec(1000000);

void init(int node, int l, int r){
    if(l == r){
        seg[node] = vec[l];
    }
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}

ll sum(int node, int l, int r, int s, int e){
    if(r < s || e < l) return 0;
    if(s <= l && r <= e) return seg[node];
    int m = (l + r) / 2;
    return sum(node * 2, l, m, s, e) + sum(node * 2 + 1, m + 1, r, s, e);
}

void update(int node, int l, int r, int idx, ll value){
    if(l > idx || r < idx) return;
    if(l == r){
        seg[node] = value;
        vec[idx] = value;
    }
    else{
        int m = (l + r) / 2;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);            
        seg[node] = seg[node * 2] + seg[node * 2 + 1];
    }
}




int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    for(int i{0}; i < m + k; ++i){
        ll q, a, b;
        cin >> q >> a >> b;
        if(q == 1){
            a--;
            update(1, 0, n - 1, a, b);
        }
        else{
            a--;
            b--;
            cout << sum(1, 0, n - 1, a, b) << "\n";
        }
    }
}
	

