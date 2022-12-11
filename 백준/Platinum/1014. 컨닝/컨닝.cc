// 2022-12-11
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

vector<vi> g(100);
vector<int> ch(100);
vector<int> match(100, -1);

bool bipartiteMatching(int x)
{
    for(auto& nx : g[x]){
        if (ch[nx] == 0)
        {
            ch[nx] = 1;
            if (match[nx] == -1 || bipartiteMatching(match[nx]))
            {
                match[nx] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i{0}; i < n * m; ++i) g[i].clear();
        vector<vc> board(n, vc(m));
        int ans{n * m};
        fill(match.begin(), match.end(), -1);
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                cin >> board[i][j];
                if(board[i][j] == 'x') ans--;
            }
        }
        int xx[]{-1,-1,0,0,1,1};
        int yy[]{-1,1,-1,1,-1,1};
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; j += 2){
                if(board[i][j] == 'x') continue;
                for(int dir{0}; dir < 6; ++dir){                    
                    int nx{i + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || board[nx][ny] == 'x') continue;
                    g[i * m + j].push_back(nx * m + ny);                    
                }
            }
        }
        for(int i{0}; i < n * m; ++i){
            if((i % m) & 1) continue;
            fill(ch.begin(), ch.end(), 0);
            if(bipartiteMatching(i)) ans--;
        }
        cout << ans << "\n";
    }
}
	
