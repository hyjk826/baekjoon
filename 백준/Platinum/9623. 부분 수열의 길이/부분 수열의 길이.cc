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


const int sz = 5e5 + 10;
vi minSeg(sz * 4, MAX);
vi vec(sz);
int n, k;

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        minSeg[node] = value;
    }
    else{
        int m = (l + r) >> 1;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        minSeg[node] = min(minSeg[node * 2], minSeg[node * 2 + 1]);
    }
}

int query(int node, int l, int r, int s, int e){
    if (r < s || e < l) return MAX;
    if (s <= l && r <= e) return minSeg[node];
    int m = (l + r) >> 1;
    int left = query(node * 2, l, m, s, e);
    int right = query(node * 2 + 1, m + 1, r, s, e);
    return min(left, right);
}

void init(){
    for(int i{0}; i < 4 * n; ++i){
        minSeg[i] = MAX;
    }
}


int main(){
	fastio;
	int t;
    cin >> t;
    while(t--){
        init();
        cin >> n >> k;
        vl vec(n + 1);
        vl A;
        A.push_back(0);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
            vec[i] += vec[i - 1];
            A.push_back(vec[i]);
        }
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int a = lower_bound(A.begin(), A.end(), vec[n]) - A.begin(); 
        update(1, 0, (int)A.size() - 1, a, n);
        int ans{MAX};
        for(int i{n - 1}; i >= 0; --i){
            int idx = lower_bound(A.begin(), A.end(), vec[i] + k) - A.begin();
            if(idx != (int)A.size()){
                int q = query(1, 0, (int)A.size() - 1, idx, (int)A.size() - 1);
                if(q == MAX) continue;
                ans = min(ans, q - i);
            }
            a = lower_bound(A.begin(), A.end(), vec[i]) - A.begin(); 
            update(1, 0, (int)A.size() - 1, a, i);
        }
        if(ans == MAX) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}

// 0 -1 0 1 2 1

// -1 0 1 2