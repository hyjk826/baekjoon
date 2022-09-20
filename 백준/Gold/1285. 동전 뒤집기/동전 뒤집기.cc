// 2022-09-20
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
    int ans{MAX};
    for(int i{0}; i < (1 << n); ++i){
        vector<vc> copy;
        copy = board;
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1){
                for(int k{0}; k < n; ++k){
                    if(copy[k][j] == 'H') copy[k][j] = 'T';
                    else copy[k][j] = 'H';
                }
            }
        }
        int sum{0};
        for(int j{0}; j < n; ++j){
            int cnt{0};
            for(int k{0}; k < n; ++k){
                if(copy[j][k] == 'T') cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ans = min(ans, sum);
    }
    cout << ans;
}
	

