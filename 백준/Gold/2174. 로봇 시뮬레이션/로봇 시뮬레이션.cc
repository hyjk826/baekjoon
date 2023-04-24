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
    int x, y, d;
};


int main(){
	fastio;
    int m, n, a, b;
    cin >> n >> m >> a >> b;
    vector<vi> board(n  + 1, vi(m + 1));
    vector<st> loc(a);
    string dd = "ENWS";
    int xx[]{1, 0, -1, 0};
    int yy[]{0, 1, 0, -1};
    for(int i{0}; i < a; ++i){
        cin >> loc[i].x >> loc[i].y;
        board[loc[i].x][loc[i].y] = i + 1;
        char c;
        cin >> c;
        loc[i].d = dd.find(c);        
    }
    for(int i{0}; i < b; ++i){
        int idx; char c; int k;
        cin >> idx >> c >> k;
        idx--;
        if(c == 'L'){
            loc[idx].d = (loc[idx].d + k) % 4;
        }
        else if(c == 'R'){
            loc[idx].d = (loc[idx].d - k + 200) % 4;
        }
        else{
            board[loc[idx].x][loc[idx].y] = 0;
            for(int i{0}; i < k; ++i){
                loc[idx].x += xx[loc[idx].d];
                loc[idx].y += yy[loc[idx].d];
                if(loc[idx].x > n || loc[idx].x < 1 || loc[idx].y > m || loc[idx].y < 1){
                    cout << "Robot " << idx + 1 << " crashes into the wall"; return 0;
                }
                if(board[loc[idx].x][loc[idx].y]){
                    cout << "Robot " << idx + 1 << " crashes into robot " << board[loc[idx].x][loc[idx].y];
                    return 0;
                }
            }
            board[loc[idx].x][loc[idx].y] = idx + 1;
        }
    }
    cout << "OK";
}
