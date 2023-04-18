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

ll seg[400004];
ll vec[100001];
ll ans[100000];

void init(int node, int l, int r){
    if(l == r) seg[node] = 1;
    else{
        int m = (l + r) / 2;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

int update(int node, int l, int r, int k){
    if(l == r) {
        seg[node] = 0;
        return l;
    }
    else{
        int m = (l + r) >> 1;
        int a = seg[node << 1];
        int ret;
        if(a >= k) ret = update(node << 1, l, m, k);
        else ret = update(node << 1 | 1, m + 1, r, k - a);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
        return ret;
    }
}


int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vi A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i];
        A[i]++;
    }
    init(1, 0, n - 1);
    for(int i{n - 1}; i >= 0; --i){
        int k = update(1, 0, n - 1, A[i]);
        ans[i] = vec[k];
    }
    for(int i{0}; i < n; ++i){
        cout << ans[i] << "\n";
    }
}
