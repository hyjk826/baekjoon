// 2023-01-03
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

vl maxSeg(400000);

void update(int node, int l, int r, int idx, ll value){
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

ll query(int node, int l, int r, int s, int e){
    if (r < s || e < l)
        return -MAX;
    if (s <= l && r <= e)
        return maxSeg[node];
    int m = (l + r) / 2;
    ll left = query(node * 2, l, m, s, e);
    ll right = query(node * 2 + 1, m + 1, r, s, e);
    return max(left, right);
}

int main(){
	fastio;
    int n, d;
    cin >> n >> d;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vl dp(n);
    for(int i{0}; i < n; ++i){
        if(i == 0) dp[i] = vec[i];
        else dp[i] = max(1LL * vec[i], query(1, 0, n - 1, max(0, i - d), i - 1) + vec[i]);
        update(1, 0, n - 1, i, dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end());
}
