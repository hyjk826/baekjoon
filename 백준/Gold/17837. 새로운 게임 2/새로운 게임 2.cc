// 2022-08-30
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
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    vector<pi> board2[12][12];
    map<int, pi> mp;
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        mp[i] = {a, b};
        board2[a][b].push_back({i, c});
    }
    int xx[]{0, 0, -1, 1};
    int yy[]{1, -1, 0, 0};
    int cnt{1};
    while(1){
        bool flag = false;
        for(int i{0}; i < m; ++i){
            int x = mp[i].first;
            int y = mp[i].second;
            for(int j{0}; j < (int)board2[x][y].size(); ++j){
                if(board2[x][y][j].first == i){
                    int d = board2[x][y][j].second;
                    int nx = x + xx[d];
                    int ny = y + yy[d];
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == 2){
                        nx = x - xx[d];
                        ny = y - yy[d];
                        if(d == 0) d = 1;
                        else if(d == 1) d = 0;
                        else if(d == 2) d = 3;
                        else if(d == 3) d = 2;
                        board2[x][y][j].second = d;
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1 || board[nx][ny] == 2){                                                        
                            break;
                        }
                    }
                    flag = true;
                    int sz = (int)board2[x][y].size() - j;
                    if(board[nx][ny] == 0){
                        for(int k{j}; k < (int)board2[x][y].size(); ++k){
                            int index = board2[x][y][k].first;
                            int dir = board2[x][y][k].second;
                            board2[nx][ny].push_back({index, dir});
                            mp[index] = {nx, ny};
                        }
                    }
                    else if(board[nx][ny] == 1){
                        for(int k{(int)board2[x][y].size() - 1}; k >= j; --k){
                            int index = board2[x][y][k].first;
                            int dir = board2[x][y][k].second;                            
                            board2[nx][ny].push_back({index, dir});
                            mp[index] = {nx, ny};
                        }                    
                    }
                    if(board2[nx][ny].size() >= 4){
                        cout << cnt;
                        return 0;
                    }
                    for(int k{0}; k < sz; ++k){
                        board2[x][y].pop_back();
                    }
                    break;
                }
            }
        }
        if(!flag || cnt == 1000){
            cout << -1;
            return 0;
        }
        cnt++;
    }
    cout << cnt;
}

