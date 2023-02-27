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

int main(){
	fastio;
    int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    int sx, sy;
    int cnt{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'P'){
                sx = i; sy = j;
            }
            else if(board[i][j] == 'K') cnt++;
        }
    }
    vector<vi> H(n, vi(n));
    int mx{0};
    int mn{MAX};
    vi A;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> H[i][j];
            mx = max(mx, H[i][j]);
            mn = min(mn, H[i][j]);
            A.push_back(H[i][j]);
        }
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int l{0}, r{mx - mn};
    int ans{-1};
    int xx[]{-1,-1,-1,0,0,1,1,1};
    int yy[]{-1,0,1,-1,1,-1,0,1};
    while(l <= r){
        int mid{(l + r) / 2};
        bool flag = false;
        for(auto& i : A){
            int a = i;
            int b = i + mid;
            queue<pi> Q;
            if(a > H[sx][sy] || H[sx][sy] > b) continue;
            vector<vi> ch(n, vi(n));
            Q.push({sx, sy});
            int cnt2{0};
            ch[sx][sy] = 1;
            while(!Q.empty()){
                int x{Q.front().first};
                int y{Q.front().second};
                Q.pop();
                if(board[x][y] == 'K') cnt2++;
                for(int dir{0}; dir < 8; ++dir){
                    int nx{x + xx[dir]};
                    int ny{y + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                    if(a > H[nx][ny] || H[nx][ny] > b) continue;
                    if(ch[nx][ny] == 0){
                        ch[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
            if(cnt == cnt2){
                flag = true; break;
            }
            if(b >= mx) break;
        }
        if(flag){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
