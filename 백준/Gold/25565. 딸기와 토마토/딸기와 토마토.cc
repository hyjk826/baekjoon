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

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> board(n, vi(m));
    int cnt{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j]) cnt++;
        }
    }
    if(cnt == 2 * k) cout << 0;
    else{
        int xx[]{-1,1,0, 0};
        int yy[]{0,0,1,-1};
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(board[i][j]){
                    int a{0}, b{0};
                    for(int dir{0}; dir < 4; ++dir){
                        int nx{i + xx[dir]};
                        int ny{j + yy[dir]};
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                        if(board[nx][ny]) {
                            if(dir < 2) a++;
                            else b++;
                        }
                    }
                    if(a && b){
                        cout << 1 << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < m; ++j){
                if(board[i][j]){
                    vp A;
                    cnt = 0;
                    if(board[i][j + 1]){
                        while(j < m && board[i][j]){
                            A.push_back({i + 1, j + 1});
                            j++;
                            cnt++;
                        }
                    }
                    else{
                        while(i < n && board[i][j]){
                            A.push_back({i + 1, j + 1});
                            i++;
                            cnt++;
                        }
                    }
                    vp ans;
                    for(int i{cnt - k}; i < (int)A.size() - (cnt - k); ++i){
                        ans.push_back(A[i]);
                    }
                    sort(ans.begin(), ans.end());
                    cout << ans.size() << "\n";
                    for(auto& i : ans) cout << i.first << " " << i.second << "\n";
                    return 0;
                }
            }
        }
    }
}
