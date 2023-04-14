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

struct st{
    int x, y, l, f;
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<st> vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].l >> vec[i].f;
    }
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(int k{m - 1}; k >= 0; --k){
                if(i >= vec[k].x && i - vec[k].x <= vec[k].l - 1 && j >= vec[k].y && j - vec[k].y <= vec[k].l - 1){
                    board[i][j] = vec[k].f;
                    break;
                }
            }
        }
    }
    int ans{0};
    for(int i{1}; i <= 7; ++i){
        for(int j{i + 1}; j <= 7; ++j){
            vector<vi> temp(n, vi(n));
            int k{0};
            for(int a{0}; a < n; ++a){
                for(int b{0}; b < n; ++b){
                    if(board[a][b] == i || board[a][b] == j){
                        temp[a][b] = 1;
                        k = 1;
                    }
                }
            }
            for(int a{1}; a < n; ++a){
                for(int b{1}; b < n; ++b){
                    if(temp[a][b] == 0) continue;
                    temp[a][b] = min({temp[a - 1][b], temp[a][b - 1], temp[a - 1][b - 1]}) + 1;
                    k = max(k, temp[a][b]);
                }
            }
            ans = max(ans, k);
        }
    }
    cout << ans * ans;
}
