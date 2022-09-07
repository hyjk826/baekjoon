// 2022-09-06
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

bool ch(vector<vi>& vec){
    for(int i{0}; i < 3; ++i){
        for(int j{0}; j < 3; ++j){
            if(vec[i][j] != vec[0][0]) return false;
        }
    }
    return true;
}

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
                if(c == 'H') board[i][j] = 0;
                else board[i][j] = 1;
            }
        }
        int ans{MAX};
        for(int i{0}; i < (1 << 3); ++i){
            for(int j{0}; j < (1 << 3); ++j){
                vi A(3), B(3);            
                int cnt1{0}, cnt2{0};
                for(int k{0}; k < 3; ++k){
                    if((i >> k) & 1) A[k]++;
                }
                for(int k{0}; k < 3; ++k){
                    if((j >> k) & 1) B[k]++;
                }
                vector<vi> copy = board;
                for(int i{0}; i < 3; ++i){
                    for(int j{0}; j < 3; ++j){
                        int a = A[i] + B[j];
                        if(a & 1){
                            copy[i][j] ^= 1;    
                        }
                    }
                }
                cnt1 = A[0] + A[1] + A[2];
                cnt2 = B[0] + B[1] + B[2];
                if(ch(copy)) ans = min(ans, cnt1 + cnt2);
                for(int i{0}; i < 3; ++i){
                    copy[i][i] ^= 1;
                }
                if(ch(copy)) ans = min(ans, cnt1 + cnt2 + 1);
                for(int i{0}; i < 3; ++i){
                    copy[i][2 - i] ^= 1;
                }
                if(ch(copy)) ans = min(ans, cnt1 + cnt2 + 2);
                for(int i{0}; i < 3; ++i){
                    copy[i][i] ^= 1;
                }
                if(ch(copy)) ans = min(ans, cnt1 + cnt2 + 1);
            }
        }
        if(ans == MAX) cout << -1;
        else cout << ans;
        cout << "\n";
    }
}
	

