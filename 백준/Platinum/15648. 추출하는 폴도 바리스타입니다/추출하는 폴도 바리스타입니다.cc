// 2023-01-09
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

vi maxSeg(2000000);

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        maxSeg[node] = max(maxSeg[node], value);
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
    int n, k, d;
    cin >> n >> k >> d;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi cnt(k);
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a = max(cnt[vec[i] % k], query(1, 1, 500000, vec[i] - d, vec[i] + d)) + 1;
        cnt[vec[i] % k] = max(cnt[vec[i] % k], a);
        update(1, 1, 500000, vec[i], a);
        ans = max(ans, a);
    }
    cout << ans;
}
