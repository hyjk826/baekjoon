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

void solve(){
    int n, k;
    cin >> n >> k;
    vs vec(2);
    for(int i{0}; i < 2; ++i){
        cin >> vec[i];
    }
    vector<vi> dp(2, vi(n, -1));
    queue<pi> Q;
    Q.push({0, 0});
    dp[0][0] = 0;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i{0}; i < 3; ++i){
            int nx, ny;
            nx = x;
            if(i == 0){
                ny = y + 1;
            }
            else if(i == 1){
                ny = y - 1;
            }
            else{
                nx ^= 1;
                ny = y + k;
            }
            if(ny >= n){
                cout << 1 << "\n"; return;
            }
            if(ny < 0) continue;
            if(vec[nx][ny] == '0') continue;
            if(ny + 1 <= dp[x][y] + 1) continue;
            if(dp[nx][ny] != -1) continue;
            dp[nx][ny] = dp[x][y] + 1;
            Q.push({nx, ny});
        }        
    }
    cout << 0 << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}