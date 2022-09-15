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

vi segTree(400000);
vi vec(100000);
int n;

// void init(int node, int l, int r){
//     if(l == r){
//         minIndexSeg[node] = l;
//         return;
//     }
//     int m = (l + r) / 2;
//     init(node * 2, l, m);
//     init(node * 2 + 1, m + 1, r);
//     int a = minIndexSeg[node * 2];
//     int b = minIndexSeg[node * 2 + 1];
//     if(vec[a] <= vec[b]) minIndexSeg[node] = a;
//     else minIndexSeg[node] = b;
// }

// int query(int node, int l, int r, int s, int e){
//     if (r < s || l > e) return -1;
//     if(s <= l && r <= e) return minIndexSeg[node];
//     int m = (l + r) / 2;
//     int a = query(node * 2, l, m, s, e);
//     int b = query(node * 2 + 1, m + 1, r, s, e);
//     if(b == -1 || vec[a] <= vec[b]) return a;
//     else return b;
// }

int init(int node, int s, int e) {
	if (s == e) return segTree[node] = s;
	int m = (s + e) / 2;
	int l = init(node * 2, s, m);
	int r = init(node * 2 + 1, m + 1, e);
	if (vec[l] <= vec[r]) return segTree[node] = l;
	else return segTree[node] = r;
}

int query(int node, int s, int e, int l, int r) {
	if (r < s || l > e) return -1;
	if (l <= s && e <= r) return segTree[node];
	int m{ (s + e) / 2 };
	int a{ query(node * 2, s, m, l, r) };
	int b{ query(node * 2 + 1, m + 1, e, l, r) };
	if (a == -1) return b;
	if (b == -1) return a;
	if (vec[a] <= vec[b]) return a;
	else return b;
}

ll ans{0};

ll f(int l, int r){
    if(l > r) return 0;
    int idx = query(1, 0, n - 1, l, r);
    ll ret = 1LL * vec[idx] * (r - l + 1);
    ret = max(ret, f(l, idx - 1));
    ret = max(ret, f(idx + 1, r));
    return ret;
}

int main() {
	fastio;
    while(1){
        cin >> n;
        if(n == 0) break;
        ans = LLONG_MAX;
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        init(1, 0, n - 1);
        cout << f(0, n - 1) << "\n";
    }
}
	

