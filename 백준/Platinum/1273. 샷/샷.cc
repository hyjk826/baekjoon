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

const int sz = 3e6 + 10;
pi seg[sz * 4];
int vec[sz];

void init(int node, int l, int r){
    if(l == r) {
        seg[node].first = vec[l];
        seg[node].second = 1;
    }
    else{
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        seg[node].second = seg[node << 1].second + seg[node << 1 | 1].second;
    }
}

void query(int node, int l, int r, int k, int& res){
    if(k < 0) return;
    if(l == r){
        res = seg[node].first;
        seg[node].second = 0;
        return;
    }   
    int m = (l + r) >> 1;
    if(seg[node << 1].second >= k) query(node << 1, l, m, k, res);
    else query(node << 1 | 1, m + 1, r, k - seg[node << 1].second, res);
    seg[node].second = seg[node << 1].second + seg[node << 1 | 1].second;
}

int main(){
	fastio;
    int n;
    cin >> n;
    vector<vi> board(3, vi(n));
	for(int i{0}; i < 3; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(i == 0){
                vec[0]++;
                vec[board[i][j]]--;
            }
            else if(i == 1){
                vec[board[0][j]] += 2;
                vec[board[0][j] + board[i][j]] -= 2;
            }
            else if(i == 2){
                vec[board[0][j] + board[1][j]] += 5;
                vec[board[0][j] + board[1][j] + board[i][j]] -= 5;
            }
        }
    }

    for(int i{1}; i <= sz; ++i){
        vec[i] += vec[i - 1];
    }
    init(1, 0, 3e6);
    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        int res{0};
        query(1, 0, 3e6, a, res);
        cout << res << "\n";
    }
}
