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

int B[500001];
int A[500001][2];

void solve(){
	int a, b;
    cin >> a >> b;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for(int i{0};;++i){
        b += i;
        if(b > 500000) break;
        B[b] = i;
    }
    queue<pi> Q;
    Q.push({a, 0});
    A[a][0] = 0;
    while(!Q.empty()){
        int x{Q.front().first};
        int cnt{Q.front().second};
        Q.pop();
        cnt++;
        for(int i{-1}; i <= 1; i += 2){            
            int nx = x + i;
            if(nx < 0 || nx > 500000) break;
            if(A[nx][cnt % 2] == -1){
                A[nx][cnt % 2] = cnt;
                Q.push({nx, cnt});
            }
        }
        int nx = x * 2;
        if(nx >= 0 && nx <= 500000){
            if(A[nx][cnt % 2] == -1){
                A[nx][cnt % 2] = cnt;
                Q.push({nx, cnt});
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i <= 500000; ++i){
        if(B[i]== -1) continue;
        for(int j{0}; j < 2; ++j){
            if(A[i][j] == -1) continue;
            if(B[i] - A[i][j] >= 0 && (B[i] - A[i][j]) % 2 == 0) {
                ans = min(ans, B[i]);
            }
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
