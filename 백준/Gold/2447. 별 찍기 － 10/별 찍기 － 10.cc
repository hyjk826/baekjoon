// 2022-09-06
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

int n;
vector<vc> board((3 * 3 * 3 * 3 * 3 * 3 * 3), vc(3 * 3 * 3 * 3 * 3 * 3 * 3, ' '));

void f(int x, int y, int k){
    if(k == 3){
        for(int i{x}; i < x + 3; ++i){
            for(int j{y}; j < y + 3; ++j){
                if(i == x + 1 && j == y + 1) continue;
                board[i][j] = '*';
            }
        }
    }
    else{
        int s = k / 3;
        f(x, y, s);
        f(x, y + s, s);
        f(x, y + 2 * s, s);
        f(x + s, y, s);
        f(x + s, y + 2 * s, s);
        f(x + 2 * s, y, s);
        f(x + 2 * s, y + s, s);
        f(x + 2 * s, y + 2 * s, s);
    }
}

int main() {
	fastio;
    cin >> n;
    f(0, 0, n);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
}
	

