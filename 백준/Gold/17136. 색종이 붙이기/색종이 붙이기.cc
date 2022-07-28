// 2022-07-28
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

vector<vi> board(10, vi(10));
int ans{MAX};
vi ch(5, 5);

void dfs(int L){
    int x, y;
    x = y = -1;
    for(int i{0}; i < 10; ++i){
        for(int j{0}; j < 10; ++j){
            if(board[i][j]){
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) break;
    }
    if(x == -1){
        ans = min(ans, L);
        return;
    }
    for(int sz{1}; sz <= 5; ++sz){
        bool flag = true;
        if(ch[sz - 1] == 0 || x + sz > 10 || y + sz > 10) continue;
        for(int i{x}; i < x + sz; ++i){
            for(int j{y}; j < y + sz; ++j){
                if(board[i][j] == 0){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag){
            for(int i{x}; i < x + sz; ++i){
                for(int j{y}; j < y + sz; ++j){
                    board[i][j] = 0;
                }
            }
            ch[sz - 1]--;
            dfs(L + 1);
            ch[sz - 1]++;
            for(int i{x}; i < x + sz; ++i){
                for(int j{y}; j < y + sz; ++j){
                    board[i][j] = 1;
                }
            }
        }
    }
}

int main() {
	fastio;
    for(int i{0}; i < 10; ++i){
        for(int j{0}; j < 10; ++j){
            cin >> board[i][j];
        }
    }
    dfs(0);
    if(ans == MAX) cout << -1;
    else cout << ans;
}

