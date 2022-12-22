// 2022-12-23
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

vi minSeg(2000010, MAX);

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        minSeg[node] = value;
    }
    else{
        int m = (l + r) / 2;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        minSeg[node] = min(minSeg[node * 2], minSeg[node * 2 + 1]);
    }
}

int query(int node, int l, int r, int s, int e){
    if (r < s || e < l) return MAX;
    if (s <= l && r <= e) return minSeg[node];
    int m = (l + r) / 2;
    return min(query(node * 2, l, m, s, e), query(node * 2 + 1, m + 1, r, s, e));
}

struct st{
    int a, b, c;
    bool operator< (const st& x) const{
        return a < x.a;
    }
};

int main(){
    int n;
    cin >> n;
    vector<st> vec(n + 1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        vec[a].a = i;
    }
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        vec[a].b = i;
    }
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        vec[a].c = i;
    }
    sort(vec.begin() + 1, vec.end());
    int ans{0};
    for(int i{1}; i <= n; ++i){
        if(query(1, 1, n, 1, vec[i].b) > vec[i].c) ans++;
        update(1, 1, n, vec[i].b, vec[i].c);
    }
    cout << ans;
}
