// 2023-01-23
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

void solve(){
    int n;
    cin >> n;
    vector<vi> board(n * n, vi(n * n));
    for(int i{0}; i < n * n; ++i){
        for(int j{0}; j < n * n; ++j){
            cin >> board[i][j];
        }
    }
    bool ok = true;
    for(int i{0}; i < n * n; ++i){
        vi ch(n * n + 1);
        int cnt{0};
        for(int j{0}; j < n * n; ++j){
            if(board[i][j] > n * n){
                ok = false;
                continue;
            }
            if(ch[board[i][j]] == 0){
                ch[board[i][j]] = 1;
                cnt++;
            }
        }
        ok &= (cnt == n * n);
    }
    for(int j{0}; j < n * n; ++j){
        vi ch(n * n + 1);
        int cnt{0};
        for(int i{0}; i < n * n; ++i){
            if(board[i][j] > n * n){
                ok = false;
                continue;
            }
            if(ch[board[i][j]] == 0){
                ch[board[i][j]] = 1;
                cnt++;
            }
        }
        ok &= (cnt == n * n);
    }
    for(int i{0}; i < n * n; i += n){
        for(int j{0}; j < n * n; j += n){
            vi ch(n * n + 1);
            int cnt{0};
            for(int a{i}; a < i + n; ++a){
                for(int b{j}; b < j + n; ++b){
                    if(board[a][b] > n * n){
                        ok = false;
                        continue;
                    }
                    if(ch[board[a][b]] == 0){
                        ch[board[a][b]] = 1;
                        cnt++;
                    }
                }
            }
            ok &= (cnt == n * n);
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
	fastio;	
	int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        cout << "Case #" << T << ": ";
        solve();
    }
}
	
