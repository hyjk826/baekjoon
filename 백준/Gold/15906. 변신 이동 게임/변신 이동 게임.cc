// 2022-11-20
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
    int x, y, flag, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

int main() {
	fastio;	
	int n, t, tx, ty;
    cin >> n >> t >> tx >> ty;
    tx--;
    ty--;
    vector<vc> board(n, vc(n));
    vector<vi> X(n);
    vector<vi> Y(n);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == '#'){
                X[i].push_back(j);
                Y[j].push_back(i);
            }
        }
    }
    for(int i{0}; i < n; ++i){
        sort(X[i].begin(), X[i].end());
        sort(Y[i].begin(), Y[i].end());
    }
    vector<vector<vi>> dijk(n, vector<vi>(n, vi(2, MAX)));
    dijk[0][0][0] = 0;
    priority_queue<st> pQ;
    pQ.push({0, 0, 0, 0});
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!pQ.empty()){
        int x{pQ.top().x};
        int y{pQ.top().y};
        int flag{pQ.top().flag};
        int w{pQ.top().w};
        pQ.pop();
        if(dijk[x][y][flag] < w) continue;
        if(flag == 0){
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if(dijk[nx][ny][0] > w + 1){
                    dijk[nx][ny][0] = w + 1;
                    pQ.push({nx, ny, 0, w + 1});
                }
            }
            if(dijk[x][y][1] > w + t){
                dijk[x][y][1] = w + t;
                pQ.push({x, y, 1, w + t});
            }
        }
        else{
            auto it = upper_bound(X[x].begin(), X[x].end(), y);
            if(it != X[x].end()){
                if(dijk[x][*it][1] > w + 1){
                    dijk[x][*it][1] = w + 1;
                    pQ.push({x, *it, 1, w + 1});
                }
            }
            it = lower_bound(X[x].begin(), X[x].end(), y);
            if(it != X[x].begin()){
                it--;
                if(dijk[x][*it][1] > w + 1){
                    dijk[x][*it][1] = w + 1;
                    pQ.push({x, *it, 1, w + 1});
                }
            }
            it = upper_bound(Y[y].begin(), Y[y].end(), x);
            if(it != Y[y].end()){
                if(dijk[*it][y][1] > w + 1){
                    dijk[*it][y][1] = w + 1;
                    pQ.push({*it, y, 1, w + 1});
                }
            }
            it = lower_bound(Y[y].begin(), Y[y].end(), x);
            if(it != Y[y].begin()){
                it--;
                if(dijk[*it][y][1] > w + 1){
                    dijk[*it][y][1] = w + 1;
                    pQ.push({*it, y, 1, w + 1});
                }
            }
            if(dijk[x][y][0] > w){
                dijk[x][y][0] = w;
                pQ.push({x, y, 0, w});
            }
        }
    }
    cout << min(dijk[tx][ty][0], dijk[tx][ty][1]);
}
	

