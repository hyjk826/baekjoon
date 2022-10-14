// 2022-10-15
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
	int n, m;
    cin >> n >> m;
    vector<vi> board(100, vi(100));
    for(int i{0}; i < n; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        for(int j{a}; j < c; ++j){
            for(int k{b}; k < d; ++k){
                board[j][k]++;
            }
        }
    }
    int ans{0};
    for(int i{0}; i < 100; ++i){
        for(int j{0}; j < 100; ++j){
            if(board[i][j] > m) ans++;
        }
    }
    cout << ans;
}
	

