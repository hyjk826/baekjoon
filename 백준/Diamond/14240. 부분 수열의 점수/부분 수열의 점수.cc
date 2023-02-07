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

const ll inf = 2e18;

struct Line{
	ll a, b;
	ll get(ll x){
		return a * x + b;
	}
};

struct Node{
	int l, r; 
	ll s, e; 
	Line line;
};

struct Li_Chao{
	vector<Node> tree;
	void init(ll s, ll e){
		tree.push_back({ -1, -1, s, e, { 0, -inf } });
	}
	void update(Line v, int node = 0){
		ll s = tree[node].s, e = tree[node].e;
		ll m = (s + e) >> 1;
		Line low = tree[node].line, high = v;
		if (low.get(s) > high.get(s)) swap(low, high);
		if (low.get(e) <= high.get(e)){
			tree[node].line = high; return;
		}
		if (low.get(m) < high.get(m)){
			tree[node].line = high;
			if (tree[node].r == -1){
				tree[node].r = tree.size();
				tree.push_back({ -1, -1, m + 1, e, { 0, -inf } });
			}
			update(low, tree[node].r);
		}
		else{
			tree[node].line = low;
			if (tree[node].l == -1){
				tree[node].l = tree.size();
				tree.push_back({ -1, -1, s, m, { 0, -inf } });
			}
			update(high, tree[node].l);
		}
	}
	ll query(ll x, int node = 0){
		if (node == -1) return -inf;
		ll s = tree[node].s, e = tree[node].e;
		ll m = (s + e) >> 1;
		if (x <= m) return max(tree[node].line.get(x), query(x, tree[node].l));
		else return max(tree[node].line.get(x), query(x, tree[node].r));
	}
};


int main(){
	fastio;
    int n;
    cin >> n;
    ll ans{0};
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        ans = max(ans, vec[i]);
    }
    vl A = vec;
    for(int i{1}; i <= n; ++i){
        A[i] += A[i - 1];
    }
    vl B = A;
    for(int i{1}; i <= n; ++i){
        B[i] += B[i - 1];
    }
    Li_Chao LCT;
    LCT.init(-2e12, 2e12);
    LCT.update({-1,0});
    for(int i{2}; i <= n; ++i){
        ans = max(ans, A[i] * (i + 1) - B[i - 1] + LCT.query(A[i]));
        LCT.update({-i, B[i - 2]});
    }
    cout << ans << "\n";
}
