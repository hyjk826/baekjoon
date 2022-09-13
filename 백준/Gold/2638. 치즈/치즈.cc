#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_set>
#include <map>
#include <cstring>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;


int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for (int i{ 0 }; i < n; ++i) {
        for (int j{ 0 }; j < m; ++j) {
            cin >> board[i][j];
        }
    }  
    int xx[]{ -1,0,1,0 };
    int yy[]{ 0,1,0,-1 };
    int ans{ 0 };
    board[0][0] = 2;
    while (1) {
        queue<pi> Q;
        Q.push({ 0,0 });
        vector<vi> ch(n, vi(m));
        ch[0][0] = 1;
        while (!Q.empty()) {
            int x{ Q.front().first };
            int y{ Q.front().second };
            Q.pop();
            for (int i{ 0 }; i < 4; ++i) {
                int nx{ x + xx[i] };
                int ny{ y + yy[i] };
                if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if (ch[nx][ny] == 0 && board[nx][ny] != 1) {
                    board[nx][ny] = 2;
                    ch[nx][ny] = 1;
                    Q.push({ nx,ny });
                }
            }
        }
        vector<pi> vec;
        for (int i{ 0 }; i < n; ++i) {
            for (int j{ 0 }; j < m; ++j) {
                if (board[i][j] == 1) {
                    int cnt{ 0 };
                    for (int k{ 0 }; k < 4; ++k) {
                        int nx = i + xx[k];
                        int ny = j + yy[k];
                        if (board[nx][ny] == 2) cnt++;
                    }
                    if (cnt >= 2) vec.push_back({ i,j });
                }
            }
        }
        for (auto& i : vec) {
            board[i.first][i.second] = 2;
        }
        ans++;
        if (vec.size() == 0) break;
    }
    cout << ans - 1;
}