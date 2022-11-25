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
	int a, b, c, cnt;
};

struct st2{
	int x, y, w;
	bool operator< (const st2& a) const{
		return w < a.w;
	}
};


int main() {
	fastio;	
	int xx[]{-1,0,1,0};
	int yy[]{0,1,0,-1};
	int n, m;
	cin >> n >> m;
	vector<vi> board(n, vi(m, -2));
	int k;
	cin >> k;
	vector<vi> ch(n, vi(m, -1));
	priority_queue<st2> pQ;
	while(k--){
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		pQ.push({a, b, c});
		ch[a][b] = c;
	}
	while(!pQ.empty()){
		int x{pQ.top().x};
		int y{pQ.top().y};
		int w{pQ.top().w};
		pQ.pop();
		if(w == 0) continue;
		if(ch[x][y] > w) continue;
		for(int dir{0}; dir < 4; ++dir){
			int nx{x + xx[dir]};
			int ny{y + yy[dir]};
			if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
			if(ch[nx][ny] < w - 1){
				ch[nx][ny] = w - 1;
				pQ.push({nx, ny, w - 1});
			}
		}
	}
	for(int i{0}; i < n; ++i){
		for(int j{0}; j < m; ++j){
			if(ch[i][j] != -1) board[i][j] = -1;
		}
	}
	queue<pi> Q;
	Q.push({0, 0});
	board[0][0] = 0;
	while(!Q.empty()){
		int x{Q.front().first};
		int y{Q.front().second};
		Q.pop();
		for(int dir{0}; dir < 4; ++dir){
			int nx{x + xx[dir]};
			int ny{y + yy[dir]};
			if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
			if(board[nx][ny] == -2){
				board[nx][ny] = board[x][y] + 1;
				Q.push({nx, ny});
			}
		}
	}
	if(board[n - 1][m - 1] == -2) cout << "NO\n";
	else{
		cout << "YES\n";
		cout << board[n - 1][m - 1];
	}
}
	

