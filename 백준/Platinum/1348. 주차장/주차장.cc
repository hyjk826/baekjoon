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

vi match(100, -1);
vi ch(100);
vector<vi> g(100);

bool bipartiteMatching(int x){
    for(auto& i : g[x]){
        if(ch[i] == 0){
            ch[i] = 1;
            if(match[i] == -1 || bipartiteMatching(match[i])){
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    vp C, P;
    vector<vi> num(n, vi(m));
    int a{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'C') C.push_back({i, j});
            else if(board[i][j] == 'P'){ 
                P.push_back({i, j});
                num[i][j] = a++;
            }
        }
    }
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    vector<vp> dist(100);
    for(int i{0}; i < (int)C.size(); ++i){
        vector<vi> ch(n, vi(m, -1));
        queue<pi> Q;
        Q.push({C[i].first, C[i].second});
        ch[C[i].first][C[i].second] = 0;
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            if(board[x][y] == 'P'){
                dist[i].push_back({ch[x][y], num[x][y]});
            }
            for(int dir{0}; dir < 4; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if(board[nx][ny] == 'X') continue;
                if(ch[nx][ny] == -1){
                    ch[nx][ny] = ch[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    for(int i{0}; i < (int)C.size(); ++i){
        sort(dist[i].begin(), dist[i].end());
    }
    if(C.size() == 0){
        cout << 0; return 0;
    }
    int l{1}, r{n * m};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) / 2};
        fill(match.begin(), match.end(), -1);
        for(int i{0}; i < (int)C.size(); ++i){
            g[i].clear();
            for(auto& j : dist[i]){
                if(j.first > mid) break;
                g[i].push_back(j.second);
            }
        }
        int cnt{0};
        for(int i{0}; i < (int)C.size(); ++i){
            fill(ch.begin(), ch.end(), 0);
            if(bipartiteMatching(i)){
                cnt++;
            }
        }
        if(cnt == (int)C.size()){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
