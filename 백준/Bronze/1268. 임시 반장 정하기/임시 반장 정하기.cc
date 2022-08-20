// 2022-08-21
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

int main(){
    fastio;
    int n;
    cin >> n;
	vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 5; ++j){
            cin >> board[i][j];
        }
    }
    int mx{-1};
    int ans{0};
    for(int i{0}; i < n; ++i){
        int cnt{0};        
        for(int j{0}; j < n; ++j){
            bool flag = 0;
            if(i == j) continue;
            for(int k{0}; k < 5; ++k){
                flag |= (board[j][k] == board[i][k]);
            }
            if(flag) cnt++;
        }
        if(mx < cnt){
            mx = cnt;
            ans = i + 1;
        }
    }
    cout << ans;
}