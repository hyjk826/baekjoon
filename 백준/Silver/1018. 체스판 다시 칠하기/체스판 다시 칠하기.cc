// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int mn{MAX};
    for(int i{0}; i <= n - 8; ++i){
        for(int j{0}; j <= m - 8; ++j){
            int cnt{0};
            for(int a{i}; a < i + 8; ++a){
                for(int b{j}; b < j + 8; ++b){
                    if((a + b) & 1){
                        if(board[a][b] == 'W') cnt++;
                    }
                    else{
                        if(board[a][b] == 'B') cnt++;
                    }
                }
            }
            mn = min(mn, cnt);
        }
    }
    for(int i{0}; i <= n - 8; ++i){
        for(int j{0}; j <= m - 8; ++j){
            int cnt{0};
            for(int a{i}; a < i + 8; ++a){
                for(int b{j}; b < j + 8; ++b){
                    if((a + b) & 1){
                        if(board[a][b] == 'B') cnt++;
                    }
                    else{
                        if(board[a][b] == 'W') cnt++;
                    }
                }
            }
            mn = min(mn, cnt);
        }
    }
    cout << mn;
}