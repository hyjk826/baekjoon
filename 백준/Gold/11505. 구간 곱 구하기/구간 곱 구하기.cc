// 2022-09-15
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

vl sumSeg(4000000);
vl vec(1000000);

void init(int node, int l, int r){
    if(l == r) sumSeg[node] = vec[l];
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        sumSeg[node] = (sumSeg[node * 2] * sumSeg[node * 2 + 1]) % MOD;
    }
}

ll query(int node, int l, int r, int s, int e){
    if(r < s || l > e) return 1;
    if(s <= l && r <= e) return sumSeg[node];
    int m = (l + r) / 2;
    return (query(node * 2, l, m, s, e) * query(node * 2 + 1, m + 1, r, s, e)) % MOD;
}

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        sumSeg[node] = value;
        vec[idx] = value;
    }
    else{
        int m = (l + r) / 2;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        sumSeg[node] = (sumSeg[node * 2] * sumSeg[node * 2 + 1]) % MOD;
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
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            b--;
            update(1, 0, n - 1, b, c);
        }
        else{
            b--;
            c--;
            cout << query(1, 0, n - 1, b, c) << "\n";
        }
    }
}
	
