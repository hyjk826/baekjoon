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

vl maxSeg(800001, -MAX);

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

int query(int node, int l, int r, int s, int e)
{
    if (r < s || e < l)
        return -MAX;
    if (s <= l && r <= e)
        return maxSeg[node];
    int m = (l + r) / 2;
    int left = query(node * 2, l, m, s, e);
    int right = query(node * 2 + 1, m + 1, r, s, e);
    return max(left, right);
}

int main(){
	fastio;
    int n;
    cin >> n;
    vl vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vl pre = vec;
    vl A;
    for(int i{1}; i <= n; ++i){
        pre[i] += pre[i - 1];
        A.push_back(pre[i]);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i{0}; i <= n; ++i){
        pre[i] = lower_bound(A.begin(), A.end(), pre[i]) - A.begin();
    }
    vi dp(n + 1);
    update(1, 0, n - 1, pre[0], 0);
    for(int i{1}; i <= n; ++i){
        dp[i] = dp[i - 1];
        dp[i] = max(dp[i], max(0, i + query(1, 0, n - 1, 0, pre[i])));
        update(1, 0, n - 1, pre[i], dp[i] - i);
    }
    cout << *max_element(dp.begin(), dp.end());
}
