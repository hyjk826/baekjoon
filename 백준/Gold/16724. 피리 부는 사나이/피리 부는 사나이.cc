// 2022-09-14
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m;
vector<vc> board(1000, vc(1000));
int ans{0};
vector<vi> ch(1000, vi(1000));
vector<vi> finished(1000, vi(1000));
string str = "UDLR";
int xx[]{-1, 1, 0, 0};
int yy[]{0, 0, -1, 1};

void dfs(int x, int y){
    ch[x][y] = 1;
    int index;
    for(int i{0}; i < 4; ++i){
        if(str[i] == board[x][y]){
            index = i;
            break;
        }
    }
    int nx = x + xx[index];
    int ny = y + yy[index];
    if(ch[nx][ny] == 0){
       dfs(nx, ny); 
    }
    else{
        if(finished[nx][ny] == 0){
            ans++;
        }
    }
    finished[x][y] = 1;
}


int main() {
	fastio;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j] == 0){
                dfs(i, j);
            }
        }
    }
    cout << ans;
}
	

