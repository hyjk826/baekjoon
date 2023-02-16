// 2022-08-16
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
    cin >> m >> n;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int xx[]{0,-1,0,1};
    int yy[]{-1,0,1,0};
    vector<vi> ch(n, vi(m));
    int k{1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j] == 0){
                int cnt{0};
                queue<pi> Q;
                Q.push({i, j});
                ch[i][j] = k;
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    cnt++;
                    for(int dir{0}; dir < 4; ++dir){
                        if(!(board[x][y] >> dir & 1)){
                            int nx{x + xx[dir]};
                            int ny{y + yy[dir]};
                            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                            if(ch[nx][ny] == 0){
                                ch[nx][ny] = k;
                                Q.push({nx, ny});
                            }
                        }
                    }
                }
                k++;
            }
        }
    }
    vi A(k);
    vector<set<int>> B(k);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            A[ch[i][j]]++;
            for(int dir{0}; dir < 4; ++dir){
                int nx = i + xx[dir];
                int ny = j + yy[dir];
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(ch[nx][ny] != ch[i][j]){
                   B[ch[i][j]].insert(ch[nx][ny]); 
                }
            }
        }
    }
    int mx1{0}, mx2{0};
    for(int i{1}; i < k; ++i){
        mx1 = max(mx1, A[i]);
    }
    for(int i{1}; i < k; ++i){
        for(auto& j : B[i]){
            mx2 = max(mx2, A[i] + A[j]);
        }
    }
    cout << k - 1 << "\n";
    cout << mx1 << "\n";
    cout << mx2 << "\n";
}

