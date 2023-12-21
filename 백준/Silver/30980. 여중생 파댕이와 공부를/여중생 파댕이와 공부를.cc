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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n, m;
    cin >> n >> m;
    vector<vc> board(3*n, vc(8*m));
    for(int i{0}; i < 3 * n; ++i){
        for(int j{0}; j < 8 * m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < 3 * n; i += 3){
        for(int j{0}; j < 8 * m; j += 8){
            string str;
            int x = i + 1;
            int y = j + 1;
            vi tmp;
            while(board[x][y] != '.'){
                if(board[x][y] >= '0' && board[x][y] <= '9'){
                    str += board[x][y];
                }
                else {
                    tmp.push_back(stoi(str));
                    str.clear();
                }
                y++;
            }
            tmp.push_back(stoi(str));
            if(tmp[0] + tmp[1] == tmp[2]){
                for(int a{1}; a < 6; ++a){
                    board[i][j + a] = '*';
                    board[i + 2][j + a] = '*';
                }
                board[i + 1][j] = '*';
                if(board[i + 1][6 + j] == '.') board[i + 1][6 + j] = '*';
                else {
                    board[i][6 + j] = board[i + 2][6 + j] = '*';
                    board[i + 1][7 + j] = '*';
                }
            }
            else{
                board[i + 1][j + 2] = board[i][j + 3] = board[i + 2][j + 1] = '/';
            }
        }
    }
    for(int i{0}; i < 3 * n; ++i){
        for(int j{0}; j < 8 * m; ++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
