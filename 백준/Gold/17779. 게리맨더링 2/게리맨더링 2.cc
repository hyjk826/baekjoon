// 2022-07-31
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

bool f(int a, int b){
    return 1 <= a && a <= n && 1 <= b && b <= n;
}
int main() {
	fastio;
    cin >> n;
    vector<vi> board(n + 1, vi(n + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            cin >> board[i][j];
        }
    }
    int ans{MAX};
    for(int a{1}; a <= n; ++a){
        for(int b{1}; b <= n; ++b){
            for(int d1{1}; d1 <= n; ++d1){
                for(int d2{1}; d2 <= n; ++d2){
                    bool flag = true;
                    flag &= f(a + d1, b - d1);
                    flag &= f(a + d2, b + d2);
                    flag &= f(a + d1 + d2, b - d1 + d2);
                    if(!flag) continue;
                    vi cnt(5);
                    for(int i{1}; i <= n; ++i){
                        for(int j{1}; j <= n; ++j){                            
                            if(i < a + d1 && j <= b && i + j < a + b) cnt[0] += board[i][j];
                            else if(i <= a + d2 && j > b && i - j < a - b) cnt[1] += board[i][j];
                            else if(a + d1 <= i && j < b - d1 + d2 && i - j > a - b + 2 * d1) cnt[2] += board[i][j];
                            else if(a + d2 < i && b - d1 + d2 <= j && i + j > a + b + 2 * d2) cnt[3] += board[i][j];
                            else cnt[4] += board[i][j];
                        }
                    }
                    sort(cnt.begin(), cnt.end());
                    ans = min(ans, cnt.back() - cnt.front());
                }
            }
        }
    }
    cout << ans;
}

