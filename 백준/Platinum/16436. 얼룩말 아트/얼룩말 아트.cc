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

int board[2501][2501];
int board2[5010][5010];

int main(){
	fastio;
	int n, m, q;
    cin >> m >> n >> q;
    for(int i{0}; i < q; ++i){
        int op;
        cin >> op;
        if(op == 1){
            int x1, y1, x2, y2;
            cin >> y1 >> x1 >> y2 >> x2;
            board[x1][y1]++;
            board[x2 + 1][y2 + 1]++;
            board[x1][y2 + 1]--;
            board[x2 + 1][y1]--;
        }
        else{
            int x, y, k;
            cin >> y >> x >> k;
            int x1 = x - k - y + 2500;
            int y1 = x - k + y;
            int x2 = x + k - y + 2500;
            int y2 = x + k + y;
            board2[x1][y1]++;
            board2[x2 + 1][y2 + 1]++;
            board2[x1][y2 + 1]--;
            board2[x2 + 1][y1]--;
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{1}; j < m; ++j){
            board[i][j] += board[i][j - 1];
        }
    }
    for(int j{0}; j < m; ++j){
        for(int i{1}; i < n; ++i){
            board[i][j] += board[i - 1][j];
        }
    }
    for(int i{0}; i < 5000; ++i){
        for(int j{1}; j < 5000; ++j){
            board2[i][j] += board2[i][j - 1];
        }
    }
    for(int j{0}; j < 5000; ++j){
        for(int i{1}; i < 5000; ++i){
            board2[i][j] += board2[i - 1][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            int cnt = board[i][j] + board2[i - j + 2500][i + j];
            if(cnt & 1) cout << '#';
            else cout << '.';
        }
        cout << "\n";
    }
}

