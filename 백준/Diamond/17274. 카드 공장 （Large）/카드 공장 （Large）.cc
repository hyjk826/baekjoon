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

struct SparseTable{
	vector<vi> lookup;
	SparseTable(vi& arr){
		lookup.resize((int)arr.size(), vi(20));
		int n = (int)arr.size();
		for (int i = 0; i < n; i++)
			lookup[i][0] = arr[i];
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; (i + (1 << j) - 1) < n; i++) {
				lookup[i][j] = max(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int L, int R){
		int j = (int)log2(R - L + 1);
		return max(lookup[L][j], lookup[R - (1 << j) + 1][j]);
	}
};

vi A, B;
vector<vi> seg(800010);
vp Q;

void init(int node, int l, int r){
    if(l == r) seg[node].push_back(Q[l].first);
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
        return seg[node].end() - lower_bound(seg[node].begin(), seg[node].end(), k);
    }
    int m = (l + r) / 2;
    return query(node * 2, l, m, s, e, k) + query(node * 2 + 1, m + 1, r, s, e, k);
}



int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second; 
    }
    Q.resize(q);
    for(int i{0}; i < q; ++i){
        cin >> Q[i].first;
        Q[i].second = i;
    }
    init(1, 0, q - 1);
    sort(Q.begin(), Q.end());
    for(auto& i : Q){
        A.push_back(i.first);
        B.push_back(i.second);
    }    
    SparseTable sp(B);
    ll ans{0};
    for(int i{0}; i < n; ++i){
        int a = min(vec[i].first, vec[i].second);
        int b = max(vec[i].first, vec[i].second);
        int l = lower_bound(A.begin(), A.end(), a) - A.begin();
        int r = lower_bound(A.begin(), A.end(), b) - A.begin();
        if(l == r){
            int k = query(1, 0, q - 1, 0, q - 1, b);
            if(k & 1) ans += vec[i].second;
            else ans += vec[i].first;
        }
        else{
            int idx = sp.query(l, r - 1);
            int k{0};
            if(idx + 1 <= q - 1) k = query(1, 0, q - 1, idx + 1, q - 1, b);
            if(k & 1) ans += a;
            else ans += b;
        }   
    }
    cout << ans;
}
