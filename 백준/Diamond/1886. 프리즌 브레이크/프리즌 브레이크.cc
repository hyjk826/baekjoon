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


vp D, A;
int n, m;
char board[12][12];
int board2[12][12];
int dist[101][101];
int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};
int d{1}, a{1};

const int sz = 10000 + 10;
vector<vi> g(sz);
vi ch(sz);
vi match(sz);

bool bipartiteMatching(int x)
{
    for(auto& nx : g[x]){
        if (ch[nx] == 0)
        {
            ch[nx] = 1;
            if (match[nx] == 0 || bipartiteMatching(match[nx]))
            {
                match[nx] = x;
                return true;
            }
        }
    }
    return false;
}

int f(int mid){
    fill(match.begin(), match.end(), 0);
    for(int i{1}; i < a; ++i){
        g[i].clear();
        for(int j{1}; j < d; ++j){
            if(dist[i][j] == -1) continue;
            if(dist[i][j] <= mid) {
                for(int k{dist[i][j]}; k <= mid; ++k) g[i].push_back(j * 100 + k);
            }
        }
    }
    int ret{0};
    for(int i{1}; i < a; ++i){
        fill(ch.begin(), ch.end(), 0);
        if(bipartiteMatching(i)) ret++;
    }
    return ret;
}

void solve(){    
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'D'){
                board2[i][j] = d++;
                D.push_back({i, j});
            }
            else if(board[i][j] == '.'){
                board2[i][j] = a++;
                A.push_back({i, j});
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    for(int i{0}; i < (int)D.size(); ++i){
        queue<pi> Q;
        Q.push({D[i].first, D[i].second});
        vector<vi> temp(n, vi(m, -1));
        temp[D[i].first][D[i].second] = 0;
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == '.' && temp[nx][ny] == -1){
                    temp[nx][ny] = temp[x][y] + 1;
                    dist[board2[nx][ny]][board2[D[i].first][D[i].second]] = temp[nx][ny];
                    Q.push({nx, ny});
                }
            }
        }
    }
    int l{1}, r{100};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        if(f(mid) == a - 1){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(ans == -1) cout << "impossible";
    else cout << ans;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
