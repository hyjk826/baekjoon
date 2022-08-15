// 2022-08-15
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
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int ans{MAX};
    for(int i{0}; i < (1 << n); ++i){
        vi A, B;
        for(int j{0}; j < n; ++j){
            if(i >> j & 1){
                A.push_back(j);
            }
            else B.push_back(j);
        }
        if(A.size() == 0 || B.size() == 0) continue;
        int a{0}, b{0};
        for(int j{0}; j < (int)A.size(); ++j){
            for(int k{0}; k < (int)A.size(); ++k){
                a += board[A[j]][A[k]];
            }
        }
        for(int j{0}; j < (int)B.size(); ++j){
            for(int k{0}; k < (int)B.size(); ++k){
                b += board[B[j]][B[k]];
            }
        }
        ans = min(ans, abs(a - b));
    }
    cout << ans;
}

