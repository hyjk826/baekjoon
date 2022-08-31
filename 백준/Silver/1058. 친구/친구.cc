// 2022-08-31
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
    int n;
    cin >> n;
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int mx{0};
    for(int i{0}; i < n; ++i){
        int cnt{0};
        for(int j{0}; j < n; ++j){
            if(i == j) continue;
            if(board[i][j] == 'Y'){
                cnt++;
            }
            else{
                for(int k{0}; k < n; ++k){
                    if(board[i][k] == 'Y' && board[j][k] == 'Y'){
                        cnt++;
                        break;
                    }
                }
            }
        }
        mx = max(mx, cnt);
    }
    cout << mx;
}

