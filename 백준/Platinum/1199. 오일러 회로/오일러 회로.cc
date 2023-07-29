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
    vector<vi> board(n, vi(n));
    bool ok = true;
    for(int i{0}; i < n; ++i){
        int degree{0};
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
            degree += board[i][j];
        }
        if(degree & 1) ok = false;
    }
    if(!ok) cout << -1 << "\n";
    else{
        vi idx(n);
        function<void(int)> f = [&](int cur){
            for(int& i = idx[cur]; i < n; ++i){
                if(board[cur][i]){
                    board[cur][i]--;
                    board[i][cur]--;
                    f(i);
                }
            }
            cout << cur + 1 << " ";
        };
        f(0);
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
