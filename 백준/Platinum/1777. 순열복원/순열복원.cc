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

int n;
vi seg(100000 * 4);
vi ans(100000);

void init(int node, int l, int r){
    if(l == r) seg[node]++;
    else{
        int mid{(l + r) >> 1};
        init(node << 1, l, mid);
        init(node << 1 | 1, mid + 1, r);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

void update(int node, int l, int r, int cnt, int k){
    if(l == r){
        seg[node] = 0;
        ans[l] = k;
    }
    else{
        int mid{(l + r) >> 1};
        if(cnt <= seg[node << 1]) update(node << 1, l, mid, cnt, k);
        else update(node << 1 | 1, mid + 1, r, cnt - seg[node << 1], k);
        seg[node] = seg[node << 1] + seg[node << 1 | 1];
    }
}

int main(){
	fastio;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        vec[i]++;
    }
    init(1, 0, n - 1);
    for(int i{n - 1}; i >= 0; --i){
        update(1, 0, n - 1, vec[i], i + 1);
    }
    for(int i{n - 1}; i >= 0; --i){
        cout << ans[i] << " ";
    }
}
