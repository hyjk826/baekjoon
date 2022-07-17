// 2022-07-17
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vp seg(400001);
vi vec(100001);

void init(int node, int start, int end) {  
    if (start == end){
        seg[node] = {vec[start], vec[start]};
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    seg[node] = {max(seg[node * 2].first, seg[node * 2 + 1].first), min(seg[node * 2].second, seg[node * 2 + 1].second)};
}

pi f(int node, int sumFrom, int sumTo, int start, int end) {
    if (start > sumTo || end < sumFrom) return {-1, MAX};
    if (sumFrom <= start && end <= sumTo) return seg[node];
    int mid = (start + end) / 2;
    pi a = f(node * 2, sumFrom, sumTo, start, mid);
    pi b = f(node * 2 + 1, sumFrom, sumTo, mid + 1, end);
    return {max(a.first, b.first), min(a.second, b.second)};
}
void update(int node, int start, int end, int index, ll newValue) {
    if (start > index || end < index) return;
    if (start == end){
        seg[node] = {newValue, newValue};
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, newValue);
    update(node * 2 + 1, mid + 1, end, index, newValue);
    seg[node] = {max(seg[node * 2].first, seg[node * 2 + 1].first), min(seg[node * 2].second, seg[node * 2 + 1].second)};
}

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i{0}; i < n; ++i){
            vec[i] = i;
        }
        init(1, 0, n - 1);
        while(q--){
            int a, b, c;
            cin >> a >> b >> c;
            if(a == 0){
                swap(vec[b], vec[c]);
                update(1, 0, n - 1, b, vec[b]);
                update(1, 0, n - 1, c, vec[c]);
            }
            else{
                pi k = f(1, b, c, 0, n - 1); 
                if(k.first == c && k.second == b) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}
