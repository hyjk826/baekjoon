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
    int n;
    cin >> n;
    vector<vi> board(n + 1, vi(n + 1));
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            board[i][j] += board[i][j - 1];
        }
    }
    for(int j{1}; j <= n; ++j){
        for(int i{1}; i <= n; ++i){
            board[i][j] += board[i - 1][j];
        }
    }
    function<int(int,int,int,int)> f = [&](int x1, int y1, int x2, int y2){
        int ret{0};
        ret += board[x2][y2];
        ret -= board[x1 - 1][y2];
        ret -= board[x2][y1 - 1];
        ret += board[x1 - 1][y1 - 1];
        return ret;
    };
    ll ans{0};
    for(int i{1}; i < n; ++i){
        for(int j{1}; j < n; ++j){
            unordered_map<int, int> A, B;
            for(int x{1}; x <= i; ++x){
                for(int y{1}; y <= j; ++y){
                    A[f(x, y, i, j)]++;
                }
            }
            for(int x{i + 1}; x <= n; ++x){
                for(int y{j + 1}; y <= n; ++y){
                    B[f(i + 1, j + 1, x, y)]++;
                }
            }
            for(auto& x : A){
                if(B.count(x.first)) ans += 1LL * x.second * B[x.first];
            }
        }
    }
    for(int i{1}; i < n; ++i){
        for(int j{2}; j <= n; ++j){
            unordered_map<int, int> A, B;
            for(int x{1}; x <= i; ++x){
                for(int y{j}; y <= n; ++y){
                    A[f(x, j, i, y)]++;
                }
            }
            for(int x{i + 1}; x <= n; ++x){
                for(int y{1}; y < j; ++y){
                    B[f(i + 1, y, x, j - 1)]++;
                }
            }
            for(auto& x : A){
                if(B.count(x.first)) ans += 1LL * x.second * B[x.first];
            }
        }
    }
    cout << ans;
}
