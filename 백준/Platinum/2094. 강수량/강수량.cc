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


const int sz = 5e4 + 10;
vi minSeg(sz * 4);

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        minSeg[node] = value;
    }
    else{
        int m = (l + r) >> 1;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        minSeg[node] = max(minSeg[node * 2], minSeg[node * 2 + 1]);
    }
}

int query(int node, int l, int r, int s, int e){
    if (r < s || e < l) return -MAX;
    if (s <= l && r <= e) return minSeg[node];
    int m = (l + r) >> 1;
    int left = query(node * 2, l, m, s, e);
    int right = query(node * 2 + 1, m + 1, r, s, e);
    return max(left, right);
}

int main(){
	fastio;
    int n, q;
    cin >> n;
    vp vec(n);
    vi A;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        A.push_back(vec[i].first);
        update(1, 0, n - 1, i, vec[i].second);
    }
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        int idx1 = lower_bound(A.begin(), A.end(), a) - A.begin();
        int idx2 = lower_bound(A.begin(), A.end(), b) - A.begin();
        bool ok1 = false;
        bool ok2 = false;
        if(idx1 != n && A[idx1] == a) ok1 = true;
        if(idx2 != n && A[idx2] == b) ok2 = true;
        if(ok1 && ok2){
            if(vec[idx1].second >= vec[idx2].second){
                if(idx2 == idx1 + 1 || query(1, 0, n - 1, idx1 + 1, idx2 - 1) < vec[idx2].second) {
                    if(idx2 - idx1 == b - a) cout << "true\n";
                    else cout << "maybe\n";
                }
                else cout << "false\n";
            }
            else cout << "false\n";
        }
        else if(ok1){
            idx2--;
            if(idx1 == idx2){
                cout << "maybe\n";
            }
            else if(query(1, 0,  n - 1, idx1 + 1, idx2) < vec[idx1].second) cout << "maybe\n";
            else cout << "false\n";
        }
        else if(ok2){
            if(idx1 == idx2){
                cout << "maybe\n";
            }
            else if(query(1, 0,  n - 1, idx1, idx2 - 1) < vec[idx2].second) cout << "maybe\n";
            else cout << "false\n";
        }
        else {
            cout << "maybe\n";
        }
    }
}
