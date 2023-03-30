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

struct seg{
    vi maxSeg;
    seg(int sz){
        maxSeg.resize(sz * 4, -MAX);
    }
    void init(int node, int l, int r, vi& vec){
        if (l == r){
            maxSeg[node] = vec[l];
            return;
        }
        int m = (l + r) / 2;
        init(node * 2, l, m, vec);
        init(node * 2 + 1, m + 1, r, vec);
        maxSeg[node] = max(maxSeg[node * 2], maxSeg[node * 2 + 1]);
    }

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

    int query(int node, int l, int r, int s, int e){
        if (r < s || e < l)
            return -MAX;
        if (s <= l && r <= e)
            return maxSeg[node];
        int m = (l + r) / 2;
        int left = query(node * 2, l, m, s, e);
        int right = query(node * 2 + 1, m + 1, r, s, e);
        return max(left, right);
    }
};

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    seg s(n + 1);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi A = vec;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i{0}; i < n; ++i){
        vec[i] = lower_bound(A.begin(), A.end(), vec[i]) - A.begin() + 1;
    }
    seg inc3(n + 2), inc2(n + 2), dec3(n + 2), dec2(n + 2);
    for(int i{0}; i < n; ++i){
        int k = inc2.query(1, 0, n, 0, vec[i] - 1);
        int a = inc3.query(1, 0, n, 0, vec[i] - 1);
        if(a >= 3) k = max(k ,a);
        inc3.update(1, 0, n, vec[i], k + 1);

        k = dec2.query(1, 0, n, vec[i] + 1, n);
        a = dec3.query(1, 0, n, vec[i] + 1, n);
        if(a >= 3) k = max(k, a);
        dec3.update(1, 0, n, vec[i], k + 1);

        k = dec3.query(1, 0, n, 0, vec[i] - 1);        
        inc2.update(1, 0, n, vec[i], k + 1);        

        k = inc3.query(1, 0, n, vec[i] + 1, n);
        dec2.update(1, 0, n, vec[i], k + 1);        

        inc3.update(1, 0, n, vec[i], 1);
        dec3.update(1, 0, n, vec[i], 1);
    }
    int ans{0};
    ans = max(ans, inc3.query(1, 0, n, 0, n));
    ans = max(ans, dec3.query(1, 0, n, 0, n));
    if(ans >= 3) cout << ans;
    else cout << 0;
}
