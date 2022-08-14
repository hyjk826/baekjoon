// 2022-08-14
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

int n, m, k;
vector<vi> board;

void f(){
    int a = m;
    int b = n;
    for(int i{0}; i < min(n, m) / 2; ++i){
        int k = board[i][i];
        for(int j{i}; j < i + a - 1; ++j){
            board[i][j] = board[i][j + 1];
        }
        for(int j{i}; j < i + b - 1; ++j){
            board[j][m - i - 1] = board[j + 1][m - i - 1];
        }
        for(int j{m - 1 - i}; j > m - 1 - i - (a - 1); --j){
            board[n - 1 - i][j] = board[n - 1 - i][j - 1];
        }
        for(int j{n - 1 - i}; j > n - 1 - i - (b - 1); --j){
            board[j][i] = board[j - 1][i];
        }
        board[i + 1][i] = k;
        a -= 2;
        b -= 2;
    }
}

int main() {
	fastio;    
    cin >> n >> m >> k;
    board.resize(n, vi(m));    
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < k; ++i){
        f();
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

