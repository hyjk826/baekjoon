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

struct st{
    int x, y, state;
};

int main(){
	fastio;
    int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    vp B, E;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'B') B.push_back({i, j});
            else if(board[i][j] == 'E') E.push_back({i, j});
            if(board[i][j] == 'B' || board[i][j] == 'E') board[i][j] = '0';
        }
    }
    sort(B.begin(), B.end());
    sort(E.begin(), E.end());
    int ch[50][50][2];
    memset(ch, -1, sizeof(ch));
    int x = B[1].first;
    int y = B[1].second;
    queue<st> Q;
    if(B[0].first == B[1].first) {
        ch[x][y][0] = 0;
        Q.push({x, y, 0});
    }
    else {
        ch[x][y][1] = 0;
        Q.push({x, y, 1});
    }
    function<bool(int,int)> f = [&](int a, int b){
        if(a < 0 || a > n - 1 || b < 0 || b > n - 1) return false;
        return board[a][b] == '0';
    };
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int state{Q.front().state};
        Q.pop();
        bool f1 = true;
        bool f2 = true;
        if(state == 0){
            f1 &= f(x - 1, y - 1); f1 &= f(x - 1, y); f1 &= f(x - 1, y + 1);
            f2 &= f(x + 1, y - 1); f2 &= f(x + 1, y); f2 &= f(x + 1, y + 1);
            if(f(x, y - 2) && ch[x][y - 1][0] == -1){
                ch[x][y - 1][0] = ch[x][y][0] + 1;
                Q.push({x, y - 1, 0});
            }
            if(f(x, y + 2) && ch[x][y + 1][0] == -1){
                ch[x][y + 1][0] = ch[x][y][0] + 1;
                Q.push({x, y + 1, 0});
            }
            if(f1 && ch[x - 1][y][0] == -1){
                ch[x - 1][y][0] = ch[x][y][0] + 1;
                Q.push({x - 1, y , 0});
            }
            if(f2 && ch[x + 1][y][0] == -1){
                ch[x + 1][y][0] = ch[x][y][0] + 1;
                Q.push({x + 1, y, 0});
            }
            if(f1 && f2 && ch[x][y][1] == -1){
                ch[x][y][1] = ch[x][y][0] + 1;
                Q.push({x, y, 1});
            }
        }
        else{
            f1 &= f(x - 1, y - 1); f1 &= f(x, y - 1); f1 &= f(x + 1, y - 1);
            f2 &= f(x - 1, y + 1); f2 &= f(x, y + 1); f2 &= f(x + 1, y + 1);
            if(f(x - 2, y) && ch[x - 1][y][1] == -1){
                ch[x - 1][y][1] = ch[x][y][1] + 1;
                Q.push({x - 1, y, 1});
            }
            if(f(x + 2, y) && ch[x + 1][y][1] == -1){
                ch[x + 1][y][1] = ch[x][y][1] + 1;
                Q.push({x + 1, y, 1});
            }
            if(f1 && ch[x][y - 1][1] == -1){
                ch[x][y - 1][1] = ch[x][y][1] + 1;
                Q.push({x, y - 1, 1});
            }
            if(f2 && ch[x][y + 1][1] == -1){
                ch[x][y + 1][1] = ch[x][y][1] + 1;
                Q.push({x, y + 1, 1});
            }
            if(f1 && f2 && ch[x][y][0] == -1){
                ch[x][y][0] = ch[x][y][1] + 1;
                Q.push({x, y, 0});
            }
        }
    }
    int state;
    if(E[0].first == E[1].first) state = 0;
    else state = 1;
    if(ch[E[1].first][E[1].second][state] == -1) cout << 0;
    else cout << ch[E[1].first][E[1].second][state];
}
