// 2022-09-18
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
	int n, m;
    cin >> n >> m;
    vector<vi> board(n, vi(m));
    vi cnt(n);
    vi one(n);
    vi ch(m);
    bool flag = true;
    int sum{0};
    for(int i{0}; i < n; ++i){
        cin >> cnt[i];
        if(cnt[i] == 0 || cnt[i] == m){
            cout << "NO";
            return 0;
        }
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 1){
                cnt[i]--;
                ch[j] = 1;
            }
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == -1){
                if(ch[j] == 0){
                    if(cnt[i] > 0){
                        board[i][j] = 1;
                        cnt[i]--;
                        ch[j] = 1;
                    }
                }
            }
        }
    }
    for(int j{0}; j < m; ++j){
        bool ok = false;
        for(int i{0}; i < n; ++i){
            ok |= (board[i][j] == 1);
        }
        if(!ok){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
	

