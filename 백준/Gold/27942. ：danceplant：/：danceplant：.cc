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
    int n;
    cin >> n;
    vector<vi> board(n + 2, vi(n + 2));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            cin >> board[i][j];
        }
    }
    int x1{n / 2}, y1{n / 2}, x2{n / 2 + 1}, y2{n / 2 + 1};
    vi vec(4); // 'UDLR'
    for(int i{x1}; i <= x2; ++i){
        vec[2] += board[i][y1 - 1];
    }
    for(int i{x1}; i <= x2; ++i){
        vec[3] += board[i][y2 + 1];
    }
    for(int j{y1}; j <= y2; ++j){
        vec[0] += board[x1 - 1][j];
    }
    for(int j{y1}; j <= y2; ++j){
        vec[1] += board[x2 + 1][j];
    }
    string ans;
    int sum{0};
    while(1){
        int idx = max_element(vec.begin(), vec.end()) - vec.begin();
        if(vec[idx] <= 0) break;
        sum += vec[idx];
        vec[idx] = 0;
        if(idx == 2){            
            y1--;
            ans += 'L';
            for(int i{x1}; i <= x2; ++i){
                vec[2] += board[i][y1 - 1];
            }
            vec[0] += board[x1 - 1][y1];
            vec[1] += board[x2 + 1][y1];
        }
        else if(idx == 3){
            y2++;
            ans += 'R';
            for(int i{x1}; i <= x2; ++i){
                vec[3] += board[i][y2 + 1];
            }
            vec[0] += board[x1 - 1][y2];
            vec[1] += board[x2 + 1][y2];
        }
        else if(idx == 0){
            x1--;
            ans += 'U';
            for(int j{y1}; j <= y2; ++j){
                vec[0] += board[x1 - 1][j];
            }            
            vec[2] += board[x1][y1 - 1];
            vec[3] += board[x1][y2 + 1];
        }
        else {
            x2++;
            ans += 'D';
            for(int j{y1}; j <= y2; ++j){
                vec[1] += board[x2 + 1][j];
            }
            vec[2] += board[x2][y1 - 1];
            vec[3] += board[x2][y2 + 1];
        }
    }
    cout << sum << "\n" << ans;
}
