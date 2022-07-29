// 2022-07-29
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

int n;
vl vec(100000);
vi seg(400000);
vl preSum(100000);

void init(int node, int l, int r) {
    if (l == r) {
        seg[node] = l;
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    int a = seg[node * 2];
    int b = seg[node * 2 + 1];
    if(vec[a] < vec[b]) seg[node] = a;
    else seg[node] = b;
}

int query(int node, int l, int r, int s, int e) {
    if (s > r || e < l) return -1;
    if (s <= l && r <= e) return seg[node];
    int m = (l + r) / 2;
    int a = query(node * 2, l, m, s, e);
    int b = query(node * 2 + 1, m + 1, r, s, e);
    if (a == -1) return b;
    if (b == -1) return a;
    if (vec[a] < vec[b]) return a;
    else return b;
}

ll f(int l, int r) {
    if (l > r) return 0;
    if (l == r) return vec[l] * vec[l];
    ll result;
    if (l == 0) {
        result = preSum[r];
    }
    else {
        result = preSum[r] - preSum[l - 1];
    }
    int index = query(1, 0, n - 1, l, r);
    result *= vec[index];
    ll a = f(l, index - 1);
    ll b = f(index + 1, r);
    return max({ result, a, b });
}

int main() {
    fastio;
    cin >> n;
    for (int i{ 0 }; i < n; ++i) {
        cin >> vec[i];
    }
    init(1, 0, n - 1);
    preSum = vec;
    for (int i{ 1 }; i < n; ++i) {
        preSum[i] += preSum[i - 1];
    }
    cout << f(0, n - 1);
}

