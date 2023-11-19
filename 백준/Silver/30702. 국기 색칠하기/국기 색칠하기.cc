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

int xx[]{-1,0,1,0};
int yy[]{0,1,0,-1};

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vc> A(n, vc(m)), B(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> A[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> B[i][j];
        }
    }
    vector<vi> ch1(n, vi(m)), ch2(n, vi(m));
    int a{1};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch2[i][j]) continue;
            ch2[i][j] = a;
            queue<pi> Q;
            Q.push({i, j});
            vp tmp;
            while(!Q.empty()){
                int x{Q.front().first};
                int y{Q.front().second};
                Q.pop();
                tmp.push_back({x, y});
                for(int dir{0}; dir < 4; ++dir){
                    int nx{x + xx[dir]};
                    int ny{y + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    if(ch2[nx][ny]) continue;
                    if(B[nx][ny] == B[x][y]){
                        ch2[nx][ny] = a;
                        Q.push({nx, ny});
                    }
                }
            }
            for(auto& k : tmp){
                int x = k.first;
                int y = k.second;
                if(ch1[x][y]) continue;
                Q.push({x, y});
                ch1[x][y] = a;
                while(!Q.empty()){
                    int x{Q.front().first};
                    int y{Q.front().second};
                    Q.pop();
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{x + xx[dir]};
                        int ny{y + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(ch1[nx][ny]) continue;
                        if(A[nx][ny] == A[x][y]){
                            ch1[nx][ny] = a;
                            Q.push({nx, ny});
                        }
                    }   
                }
            }
            a++;
        }
    }
    if(ch1 == ch2) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
