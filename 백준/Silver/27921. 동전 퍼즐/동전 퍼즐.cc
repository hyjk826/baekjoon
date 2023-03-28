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
    int h1, w1, h2, w2;
    cin >> h1 >> w1;
    vector<vc> board1(30, vc(30));
    for(int i{10}; i < 10 + h1; ++i){
        for(int j{10}; j < 10 + w1; ++j){
            cin >> board1[i][j];
        }
    }
    cin >> h2 >> w2;
    vector<vc> board2(h2, vc(w2));
    int cnt{0};
    for(int i{0}; i < h2; ++i){
        for(int j{0}; j < w2; ++j){
            cin >> board2[i][j];
            if(board2[i][j] == 'O'){
                cnt++;
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i + h2 < 30; ++i){
        for(int j{0}; j + w2 < 30; ++j){
            int c{0};
            for(int x{0}; x < h2; ++x){
                for(int y{0}; y < w2; ++y){
                    if(board2[x][y] == 'O' && board1[i + x][j + y] == board2[x][y]) c++;
                }
            }
            ans = min(ans, cnt - c);
        }
    }
    cout << ans;
}
