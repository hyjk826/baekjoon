// 2022-07-23
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n, k;
    cin >> n >> k;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        bool f = 1;
        set<int> s;
        for(int j{0}; j < n - 1; ++j){
            if(board[i][j] == board[i][j + 1]) continue;
            if(abs(board[i][j] - board[i][j + 1]) > 1) f = 0;            
            if(board[i][j] < board[i][j + 1]){
                if(j + 1 < k){
                    f = 0;
                    break;
                }
                for(int a{j}; a > j - k; --a){
                    if(board[i][a] != board[i][j]) f = 0;
                    if(s.count(a)){
                        f = 0;
                    }
                    else s.insert(a);
                }
            }
            else{
                if(n - j + 1 < k){
                    f = 0;
                    break;
                }
                for(int a{j + 1}; a < j + 1 + k; ++a){
                    if(board[i][a] != board[i][j + 1]) f = 0;                    
                    if(s.count(a)){
                        f = 0;
                    }
                    else s.insert(a);
                }
            }
        }
        if(f) {
            ans++;
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            swap(board[i][j], board[j][i]);
        }
    }
    for(int i{0}; i < n; ++i){
        bool f = 1;
        set<int> s;
        for(int j{0}; j < n - 1; ++j){
            if(board[i][j] == board[i][j + 1]) continue;
            if(abs(board[i][j] - board[i][j + 1]) > 1) f = 0;            
            if(board[i][j] < board[i][j + 1]){
                if(j + 1 < k){
                    f = 0;
                    break;
                }
                for(int a{j}; a > j - k; --a){
                    if(board[i][a] != board[i][j]) f = 0;
                    if(s.count(a)){
                        f = 0;
                    }
                    else s.insert(a);
                }
            }
            else{
                if(n - j + 1 < k){
                    f = 0;
                    break;
                }
                for(int a{j + 1}; a < j + 1 + k; ++a){
                    if(board[i][a] != board[i][j + 1]) f = 0;                    
                    if(s.count(a)){
                        f = 0;
                    }
                    else s.insert(a);
                }
            }
        }
        if(f) {
            ans++;
        }
    }
    cout << ans;
}

