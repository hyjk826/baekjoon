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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vc> board(n + 1, vc(m + 1));
    vector<vi> J(n + 1, vi(m + 1));
    vector<vi> O(n + 1, vi(m + 1));
    vector<vi> I(n + 1, vi(m + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'J'){
                J[i][j] = 1;
            }
            else if(board[i][j] == 'O'){
                O[i][j] = 1;
            }
            else{
                I[i][j] = 1;
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= m; ++j){
            J[i][j] += J[i][j - 1];
            O[i][j] += O[i][j - 1];
            I[i][j] += I[i][j - 1];
        }
    }
    for(int j{1}; j <= m; ++j){
        for(int i{1}; i <= n; ++i){
            J[i][j] += J[i - 1][j];
            O[i][j] += O[i - 1][j];
            I[i][j] += I[i - 1][j];
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << J[x2][y2] - J[x2][y1 - 1] - J[x1 - 1][y2] + J[x1 - 1][y1 - 1] << " ";
        cout << O[x2][y2] - O[x2][y1 - 1] - O[x1 - 1][y2] + O[x1 - 1][y1 - 1] << " ";
        cout << I[x2][y2] - I[x2][y1 - 1] - I[x1 - 1][y2] + I[x1 - 1][y1 - 1] << "\n";
    }
}
