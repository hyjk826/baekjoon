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

int main(){
	fastio;
    int n, q;
    cin >> n >> q;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> postSum;
    postSum = board;
    for(int i{0}; i < n; ++i){
        for(int j{n - 2}; j >= 0; --j){
            postSum[i][j] += postSum[i][j + 1];
        }
    }
    vector<vi> mn;
    mn = postSum;
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            mn[i][j] = min(mn[i][j], mn[i - 1][j]);
        }
    }
    while(q--){
        int x, y, l;
        cin >> x >> y >> l;
        x--; y--;
        int ans = postSum[x][y];
        int sum{0};
        for(int j{y}; j < n; ++j){
            ans = min(ans, mn[x - l][j] + sum);
            sum += board[x][j];
        }
        cout << ans << "\n";
    }
}
