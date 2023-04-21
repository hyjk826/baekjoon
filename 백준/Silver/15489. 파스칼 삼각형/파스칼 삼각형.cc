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

int r, c, w;
ll board[41][41];



int main(){
	fastio;
    for(int i{1}; i <= 30; ++i){
        for(int j{1}; j <= i; ++j){
            if(j == 1 || j == i) board[i][j] = 1;
            else board[i][j] += board[i - 1][j - 1] + board[i - 1][j];
        }
    }
    cin >> r >> c >> w;
    ll ans{0};
    for(int i{r}; i < r + w; ++i){
        for(int j{c}; j < c + i - r + 1; ++j){
            ans += board[i][j];
        }
    }
    cout << ans;
}
