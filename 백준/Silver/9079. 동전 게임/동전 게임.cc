// 2022-09-19
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
    int t;
    cin >> t;
    while(t--){
        vector<vi> board(3, vi(3));
        for(int i{0}; i < 3; ++i){
            for(int j{0}; j < 3; ++j){
                char c;
                cin >> c;
                if(c == 'T') board[i][j] = 1;
            }
        }
        int ans{MAX};
        for(int i{0}; i < (1 << 8); ++i){
            vector<vi> copy;
            copy = board;
            int cnt = __builtin_popcount(i);
            for(int j{0}; j < 8; ++j){
                if((i >> j) & 1){
                    if(j < 3){
                        for(int k{0}; k < 3; ++k){
                            copy[j][k] ^= 1;
                        }
                    }
                    else if(j < 6){
                        for(int k{0}; k < 3; ++k){
                            copy[k][j - 3] ^= 1;
                        }
                    }
                    else{
                        if(j == 6){
                            for(int k{0}; k < 3; ++k){
                                copy[k][k] ^= 1;
                            }
                        }
                        else{
                            for(int k{0}; k < 3; ++k){
                                copy[k][2 - k] ^= 1;
                            }
                        }
                    }
                }
            }
            bool flag = true;
            for(int j{0}; j < 3; ++j){
                for(int k{0}; k < 3; ++k){
                    if(copy[j][k] != copy[0][0]){
                        flag = false;
                    }
                }
            }
            if(flag) ans = min(ans, cnt);
        }
        if(ans == MAX) cout << -1 << "\n";
        else cout << ans << "\n";
    }

}
	

