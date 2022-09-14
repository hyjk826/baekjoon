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

vp seg(400000);
vi vec(100000);


void init(int node, int start, int end) {  
    if (start == end){
        seg[node] = {vec[start], vec[start]};
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    seg[node].first = max(seg[node * 2].first, seg[node * 2 + 1].first);
    seg[node].second = min(seg[node * 2].second, seg[node * 2 + 1].second);
}

pi query(int node, int start, int end, int from, int to) {
    if (start > to || end < from) return {-MAX, MAX};
    if (from <= start && end <= to) return seg[node];
    int mid = (start + end) / 2;
    pi l = query(node * 2, start, mid, from, to);
    pi r = query(node * 2 + 1, mid + 1, end, from, to);
    return {max(l.first, r.first), min(l.second, r.second)};
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    for(int i{0}; i < m; ++i){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        pi ans = query(1, 0, n - 1, l, r);
        cout << ans.second << " " << ans.first << "\n";
    }
}
	

