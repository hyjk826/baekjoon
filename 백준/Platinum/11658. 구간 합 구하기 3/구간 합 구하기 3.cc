// 2023-01-19
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

int BIT[1100][1100];
int n, q;

int sum(int x, int y){
    int ret{0};
    for(int i{x}; i; i -= (i & -i)){
        for(int j{y}; j; j -= (j & -j)){
            ret += BIT[i][j];
        }
    }
    return ret;
}

void update(int x, int y, int k){
    for(int i{x}; i <= n; i += (i & -i)){
        for(int j{y}; j <= n; j += (j & -j)){
            BIT[i][j] += k;
            
        }
    }
}

int area(int x1, int y1, int x2, int y2){
    return sum(x2, y2) - sum(x2, y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1);
}

int main(){
	fastio;
    cin >> n >> q;
    vector<vi> board(n + 1, vi(n + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            cin >> board[i][j];
            update(i, j, board[i][j]);
        }
    }
    while(q--){
        int op, x1, y1, x2, y2, c;
        cin >> op;
        if(op == 0){
            cin >> x1 >> y1 >> c;
            update(x1, y1, c - board[x1][y1]);
            board[x1][y1] = c;
        }
        else if(op == 1){
            cin >> x1 >> y1 >> x2 >> y2;
            cout << area(x1, y1, x2, y2) << "\n";
        }
    }
}
