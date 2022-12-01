// 2022-12-01
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


int main() {
	fastio;
	int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    bool ok = true;
    set<int> st;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            st.insert(board[i][j]);
        }
    }
    int k = n * (n * n + 1) / 2;
    ok &= (st.size() == n * n);
    for(int i{0}; i < n; ++i){
        int sum{0};
        for(int j{0}; j < n; ++j){
            sum += board[i][j];
        }
        ok &= (sum == k);
    }
    for(int j{0}; j < n; ++j){
        int sum{0};
        for(int i{0}; i < n; ++i){
            sum += board[i][j];
        }
        ok &= (sum == k);
    }
    int sum{0};
    for(int i{0}; i < n; ++i){
        sum += board[i][i];
    }
    ok &= (sum == k);
    sum = 0;
    for(int i{0}; i < n; ++i){
        sum += board[i][n - i - 1];
    }
    ok &= (sum == k);
    if(ok) cout << "TRUE";
    else cout << "FALSE";
}
	
