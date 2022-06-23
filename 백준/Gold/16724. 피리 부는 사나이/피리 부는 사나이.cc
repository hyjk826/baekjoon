// 2022-06-24
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
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
    vector<vi> ch(n, vi(m));
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(ch[i][j] == 0){
                int a = i;
                int b = j;
                set<pi> s;
                while(1){
                    if(ch[a][b] == 1){
                        break;    
                    }
                    if(s.count({a, b})){
                        ans++;
                        break;
                    }
                    s.insert({a, b});
                    if(board[a][b] == 'D') a++;
                    else if(board[a][b] == 'U') a--;
                    else if(board[a][b] == 'L') b--;
                    else b++;
                }
                for(auto& k : s){
                    ch[k.first][k.second] = 1;
                }
            }
        }
    }
    cout << ans;
}
