// 2022-06-23
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int dp[100001][5][5]{};

int main(){
    fastio;
	vi vec;
    for(int i{0};;++i){
        int a;
        cin >> a;
        if(a == 0) break;
        vec.push_back(a);
    }
    for(int i{0}; i <= (int)vec.size(); ++i){
        for(int j{0}; j < 5; ++j){
            for(int k{0}; k < 5; ++k){
                dp[i][j][k] = MAX;
            }
        }
    }
    dp[0][0][0] = 0;
    int p[5][5];
    for(int i{1}; i <= 4; ++i){
        p[i][i] = 1;
        p[0][i] = 2;
    }
    p[1][3] = p[3][1] = p[2][4] = p[4][2] = 4;
    p[1][2] = p[2][1] = p[1][4] = p[4][1] = p[3][2] = p[2][3] = p[3][4] = p[4][3] = 3;
    for(int i{0}; i < (int)vec.size(); ++i){
        for(int j{0}; j < 5; ++j){
            for(int k{0}; k < 5; ++k){
                if(vec[i] != k){
                    dp[i + 1][vec[i]][k] = min(dp[i + 1][vec[i]][k], dp[i][j][k] + p[j][vec[i]]);
                }
                if(vec[i] != j){
                    dp[i + 1][j][vec[i]] = min(dp[i + 1][j][vec[i]], dp[i][j][k] + p[k][vec[i]]);
                }
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i < 5; ++i){
        for(int j{0}; j < 5; ++j){
            ans = min(ans, dp[(int)vec.size()][i][j]);
        }
    }
    cout << ans;
}