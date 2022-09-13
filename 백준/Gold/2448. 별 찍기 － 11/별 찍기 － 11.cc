// 2022-09-13
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

vector<vc> board;

void f(int x, int y, int k){
    if(k == 3){
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for(int i{y - 2}; i <= y + 2; ++i){
            board[x + 2][i] = '*';
        }
    }
    else{
        f(x, y, k / 2);
        f(x + k / 2, y - k / 2, k / 2);
        f(x + k / 2, y + k / 2, k / 2);
    }
}

int main() {
	fastio;
    int n;
    cin >> n;
    board.resize(n, vc(2 * n - 1, ' '));
    f(0, n - 1, n);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 2 * n - 1; ++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
}
	

