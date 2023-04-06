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

struct st {
	int v, lazy;
    st() : v(0), lazy(0){}
};

const int sz = (int)2e5 + 10;
st seg[sz * 4];
int n, q;

void propagate(int node, int l, int r){
	if (seg[node].lazy != 0) {
		seg[node].v += seg[node].lazy;
		if (l != r) {
			seg[node << 1].lazy += seg[node].lazy;
			seg[node << 1 |1].lazy += seg[node].lazy;
		}
		seg[node].lazy = 0;
	}
}

void update(int node, int l, int r, int s, int e, int diff) {
	propagate(node, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		seg[node].lazy += diff;
		propagate(node, l, r);
		return;
	}
	int m{ (l + r) >> 1 };
	update(node << 1, l, m, s, e, diff);
	update(node << 1 | 1, m + 1, r, s, e, diff);
	seg[node].v = max(seg[node << 1].v, seg[node << 1 | 1].v);
}

int query(int node, int l, int r, int s, int e) {
	propagate(node, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return seg[node].v;
	int m{ (l + r) >> 1};
	return max(query(node << 1, l, m, s, e), query(node << 1 | 1, m + 1, r, s, e));
}

int main(){
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    vi A;
    for(int i{0}; i < n; ++i){
        int x;
        cin >> x >> vec[i].first >> x >> vec[i].second;
        swap(vec[i].first, vec[i].second);
        A.push_back(vec[i].first);
        A.push_back(vec[i].second);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<vi> in((int)A.size()), out((int)A.size());
    for(int i{0}; i < n; ++i){
        vec[i].first = lower_bound(A.begin(), A.end(), vec[i].first) - A.begin();
        vec[i].second = lower_bound(A.begin(), A.end(), vec[i].second) - A.begin();
        update(1, 0, (int)A.size() - 1, vec[i].first, vec[i].second, 1);
        in[vec[i].first].push_back(i);
        out[vec[i].second].push_back(i);
    }
    int cnt{0};
    int ans{0};
    for(int i{0}; i < (int)A.size(); ++i){
        for(auto& j : in[i]){
            cnt++;
            update(1, 0, (int)A.size() - 1, vec[j].first, vec[j].second, -1);
        }
        ans = max(ans, cnt + query(1, 0, (int)A.size() - 1, 0, (int)A.size() - 1));
        for(auto& j : out[i]){
            cnt--;
        }
    }
    cout << ans;
}
