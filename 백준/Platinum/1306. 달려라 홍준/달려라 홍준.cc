// 2022-12-26
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

vi seg(4000010);
vi vec(1000001);

void update(int node, int l, int r, int idx, int value){
    if(l > idx || r < idx) return;
    if(l == r){
        if(value == 1){
            seg[node] = l;
        }
        else seg[node] = 0;
    }
    else{
        int m = (l + r) / 2;
        update(node * 2, l, m, idx, value);
        update(node * 2 + 1, m + 1, r, idx, value);
        if(vec[seg[node * 2]] > vec[seg[node * 2 + 1]]) seg[node] = seg[node * 2];
        else seg[node] = seg[node * 2 + 1];
    }
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i) {
        cin >> vec[i];
    }
    for(int i{1}; i <= 2 * m - 1; ++i){
        update(1, 1, n, i, 1);
    }
    cout << vec[seg[1]] << " ";
    for(int i{1}; i + 2 * m - 1 <= n; ++i){
        update(1, 1, n, i, -1);
        update(1, 1, n, i + 2 * m - 1, 1);
        cout << vec[seg[1]] << " ";
    }
}
