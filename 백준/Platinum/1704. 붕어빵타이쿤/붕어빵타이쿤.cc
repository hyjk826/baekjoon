// 2022-11-16
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

int xx[]{-1,0,1,0, 0};
int yy[]{0,1,0,-1, 0};
int n, m;

string f(vector<vi>& board, string str){
    for(int i{1}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i - 1][j] == 1){
                for(int dir{0}; dir < 5; ++dir){
                    int nx{i + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    board[nx][ny] ^= 1;
                }
                str += '1';
            }
            else str += '0';
        }
    }
    int cnt{0};
    for(int j{0}; j < m; ++j){
        if(board[n - 1][j] == 1) cnt++;
    }
    if(cnt == 0) return str;
    else return " ";    
}


int main() {
	fastio;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }    
    vs vec;
    for(int i{0}; i < (1 << m); ++i){
        vector<vi> copy = board;
        string str;
        for(int j{0}; j < m; ++j){
            if((i >> j) & 1){
                str += '1';
                for(int dir{0}; dir < 5; ++dir){
                    int nx{0 + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    copy[nx][ny] ^= 1;
                }
            }
            else str += '0';
        }
        string r = f(copy, str);
        if(r == " ") {
            continue;
        }
        vec.push_back(r);
    }
    if(vec.empty()) cout << "IMPOSSIBLE";
    else{
        sort(vec.begin(), vec.end(), [&](string a, string b){
            int x, y;
            x = y = 0;
            for(auto& c : a) if(c == '1') x++;
            for(auto& c : b) if(c == '1') y++;
            if(x == y){
                return a < b;
            }
            else return x < y;            
        });
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                cout << vec[0][i * m + j] << " ";
            }
            cout << "\n";
        }
    }
}
	

