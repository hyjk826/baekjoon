// 2022-12-29
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

struct Node{
    ll l, r, mid, all;
};

vector<Node> seg(12005);

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r) {
        seg[node].l += value;
        seg[node].r += value;
        seg[node].mid += value;
        seg[node].all += value;
        return;
    }
    int m = (l + r) / 2;
    update(node * 2, l, m, idx, value);
    update(node * 2 + 1, m + 1, r, idx, value);
    Node& left = seg[node * 2];
    Node& right = seg[node * 2 + 1];
    seg[node].l = max(left.l, left.all + right.l);
    seg[node].r = max(right.r, left.r + right.all);
    seg[node].mid = max({left.mid, right.mid, left.r + right.l});
    seg[node].all = left.all + right.all;
}

struct st{
    int x, y, w;
};

int main(){
	fastio;
    int n, m;
    cin >> n;
    vp A(n);
    for(int i{0}; i < n; ++i){
        cin >> A[i].first >> A[i].second;
    }
    cin >> m;
    vp B(m);
    for(int i{0}; i < m; ++i){
        cin >> B[i].first >> B[i].second;
    }
    ll c1, c2;
    cin >> c1 >> c2;
    vi X, Y;
    vector<st> vec(n + m);
    for(int i{0}; i < n + m; ++i){
        if(i < n) {
            vec[i].x = A[i].first;
            vec[i].y = A[i].second;
            vec[i].w = c1;
        }
        else{
            vec[i].x = B[i - n].first;
            vec[i].y = B[i - n].second;
            vec[i].w = -c2;
        }
        X.push_back(vec[i].x);
        Y.push_back(vec[i].y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for(int i{0}; i < n + m; ++i){
        vec[i].x = lower_bound(X.begin(), X.end(), vec[i].x) - X.begin();
        vec[i].y = lower_bound(Y.begin(), Y.end(), vec[i].y) - Y.begin();
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        if(a.y == b.y) return a.x < b.x;
        else return a.y < b.y;
    });
    ll ans{-LLONG_MAX};
    for(int i{0}; i < n + m; ++i){
        if(i && vec[i].y == vec[i - 1].y) continue;
        for(int i{0}; i <= 8000; ++i){
            seg[i].l = seg[i].r = seg[i].mid = seg[i].all = 0;
        }
        for(int j{i}; j < n + m; ++j){
            update(1, 0, n + m - 1, vec[j].x, vec[j].w);
            if(j == n - 1 || vec[j + 1].y != vec[j].y) ans = max(ans, seg[1].mid);
        }
    }
    cout << ans;
}
