// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int a{0}, b{0}, c{0};
const int sz = 3 * 3 * 3 * 3 * 3 * 3 * 3;
int board[sz][sz];
void f(int x, int y, int k){
    bool flag = true;
    for(int i{x}; i < x + k; ++i){
        for(int j{y}; j < y + k; ++j){
            if(board[i][j] != board[x][y]){
                flag = false;
            }
        }
    }
    if(flag){
        if(board[x][y] == -1) a++;
        else if(board[x][y] == 0) b++;
        else c++;
    }
    else{
        f(x, y, k / 3);
        f(x, y + k / 3, k / 3);
        f(x, y + k / 3 * 2, k / 3);
        f(x + k / 3, y, k / 3);
        f(x + k / 3, y + k / 3, k / 3);
        f(x + k / 3, y + k / 3 * 2, k / 3);
        f(x + k / 3 * 2, y, k / 3);
        f(x + k / 3 * 2, y + k / 3, k / 3);
        f(x + k / 3 * 2, y + k / 3 * 2, k / 3);
    }
}
int main(){
    fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    f(0, 0, n);
    cout << a << "\n" << b << "\n" << c;
}