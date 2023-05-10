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

vector<vi> seg(400010);
vi mx(100001);

void init(int node, int l, int r){
    if(l == r) {
        seg[node].push_back(mx[l]);        
    }
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        seg[node].resize(r - l + 1);
        merge(seg[node * 2].begin(), seg[node * 2].end(), seg[node * 2 + 1].begin(), seg[node * 2 + 1].end(), seg[node].begin());
    }
}

int query(int node, int l, int r, int s, int e, int k){
    if(s > r || e < l) return 0;
    if(s <= l && r <= e){
        return upper_bound(seg[node].begin(), seg[node].end(), k) - seg[node].begin();
    }
    int m = (l + r) / 2;
    return query(node * 2, l, m, s, e, k) + query(node * 2 + 1, m + 1, r, s, e, k);
}

int main(){
	fastio;
	for(int i{2}; i <= 100000; ++i){
        if(mx[i]) continue;
        for(int j{i}; j <= 100000; j += i){
            mx[j] = max(mx[j], i);
        }
    }
    mx[1] = MAX;
    init(1, 2, 100000);
    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        cout << query(1, 2, 100000, 2, n, k) << "\n";
    }
}
