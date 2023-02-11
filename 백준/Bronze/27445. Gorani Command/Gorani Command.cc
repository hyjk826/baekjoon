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
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        cin >> board[i][0];
    }
    for(int j{1}; j < m; ++j){
        cin >> board[n - 1][j];
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            bool ok = true;
            for(int a{0}; a < n; ++a){
                ok &= (abs(i - a) + abs(j) == board[a][0]);
            }
            for(int a{1}; a < m; ++a){
                ok &= (abs(i - (n - 1)) + abs(j - a) == board[n - 1][a]);
            }
            if(ok){
                cout << i + 1 << " " << j + 1; return 0;
            }
        }
    }
}
