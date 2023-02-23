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

const int sz = 1e6 + 10;
vl maxSeg(sz * 4);
vl A;

void init(int node, int l, int r){
    if (l == r){
        maxSeg[node] = A[l];
        return;
    }
    int m = (l + r) / 2;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
}

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        maxSeg[node] = value;
    }
    else{
        int m = (l + r) / 2;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
    }
}

ll query(int node, int l, int r, int s, int e)
{
    if (r < s || e < l)
        return -LLONG_MAX;
    if (s <= l && r <= e)
        return maxSeg[node];
    int m = (l + r) / 2;
    ll left = query(node * 2, l, m, s, e);
    ll right = query(node * 2 + 1, m + 1, r, s, e);
    return max(left, right);
}

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    A.resize(n + 1);
    vl B(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
    }
    for(int i{1}; i <= n; ++i){
        cin >> B[i];
    }
    for(int i{1}; i <= n; ++i){
        A.push_back(A[i]);
        B.push_back(B[i]);
    }
    for(int i{1}; i <= 2 * n; ++i){
        A[i] += A[i - 1];
        B[i] += B[i - 1];
    }
    init(1, 0, 2 * n);
    ll ans{-LLONG_MAX};
    for(int i{1}; i <= n; ++i){
        int idx = lower_bound(B.begin(), B.end(), B[i - 1] + k) - B.begin();
        ans = max(ans, query(1, 0, 2 * n, idx, i - 1 + n) - A[i - 1]);
    }
    cout << ans;
}
