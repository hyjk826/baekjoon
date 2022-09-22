// 2022-09-21
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

int main() {
	fastio;
    int xx[]{-1,-1,-1,0,0,1,1,1};
    int yy[]{-1,0,1,-1,1,-1,0,1};
    int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if('1' <= board[i][j] && board[i][j] <= '9'){
                cout << "*";
            }
            else{
                int sum{0};
                for(int dir{0}; dir < 8; ++dir){
                    int nx{i + xx[dir]};
                    int ny{j + yy[dir]};
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                    if('1' <= board[nx][ny] && board[nx][ny] <= '9'){
                        sum += board[nx][ny] - '0';
                    }
                }
                if(sum >= 10) cout << "M";
                else cout << sum;
            }
        }
        cout << "\n";
    }
}
	

