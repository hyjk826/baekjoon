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

int ch[301][301][11];

int main(){
	fastio;
    int n;
    cin >> n;
    vector<vi> board(n + 1, vi(n + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            cin >> board[i][j];
        }
    }
    for(int k{1}; k <= 10; ++k){
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= n; ++j){
                if(board[i][j] == k) ch[i][j][k] = 1;
            }
        }
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= n; ++j){
                ch[i][j][k] += ch[i][j - 1][k];
            }
        }
        for(int j{1}; j <= n; ++j){
            for(int i{1}; i <= n; ++i){
                ch[i][j][k] += ch[i - 1][j][k];
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int cnt{0};
        for(int k{1}; k <= 10; ++k){
            int a = ch[x2][y2][k] - ch[x2][y1 - 1][k] - ch[x1 - 1][y2][k] + ch[x1 - 1][y1 - 1][k];
            if(a) cnt++;
        }
        cout << cnt << "\n";
    }
}
