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
    int x, y, cnt;
};


int main(){
	fastio;
    int n, m, p;
    cin >> n >> m >> p;
    queue<st> Q[10];
    vi A(p + 1);
    for(int i{1}; i <= p; ++i){
        cin >> A[i];
    }
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] >= '1' && board[i][j] <= '9'){
                Q[board[i][j] - '0'].push({i, j, A[board[i][j] - '0']});
            }
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(1){
        int sum{0};
        for(int i{1}; i <= p; ++i){
            vp temp;
            while(!Q[i].empty()){
                int x{Q[i].front().x};
                int y{Q[i].front().y};
                int cnt{Q[i].front().cnt};
                Q[i].pop();
                for(int dir{0}; dir < 4; ++dir){
                    int nx{x + xx[dir]};
                    int ny{y + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    if(board[nx][ny] == '.'){
                        board[nx][ny] = char('0' + i);
                        if(cnt > 1) Q[i].push({nx, ny, cnt - 1});
                        else if(cnt == 1) temp.push_back({nx, ny});
                    }
                }
            }
            for(auto& j : temp){
                Q[i].push({j.first, j.second, A[i]});
            }
            sum += temp.size();
        }
        if(sum == 0) break;
    }
    vi ans(p + 1);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] >= '1' && board[i][j] <= '9'){
                ans[board[i][j] - '0']++;
            }
        }
    }
    for(int i{1}; i <= p; ++i){
        cout << ans[i] << " ";
    }
}
