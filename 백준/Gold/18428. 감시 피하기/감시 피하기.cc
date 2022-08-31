// 2022-09-01
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

int n;
char board[6][6];
vp t;
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};


void dfs(int L, int k){
    if(L == 3){
        int cnt{0};
        for(int i{0}; i < (int)t.size(); ++i){
            for(int dir{0}; dir < 4; ++dir){
                int x{t[i].first};
                int y{t[i].second};
                while(1){
                    x += xx[dir];
                    y += yy[dir];
                    if(x < 0 || x > n - 1 || y < 0 || y > n - 1 || board[x][y] == 'T' || board[x][y] == 'O') break;
                    if(board[x][y] == 'S'){
                        cnt++;
                    }
                }
            }
        }
        if(cnt == 0){
            cout << "YES";
            exit(0);
        }
    }
    else{
        for(int i{k + 1}; i < n *n; ++i){
            int x = i / n;
            int y = i % n;
            if(board[x][y] == 'X'){
                board[x][y] = 'O';
                dfs(L + 1, i);
                board[x][y] = 'X';
            }
        }
    }
}
int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'T'){
                t.push_back({i, j});
            }
        }
    }
    dfs(0, -1);
    cout << "NO";
}

