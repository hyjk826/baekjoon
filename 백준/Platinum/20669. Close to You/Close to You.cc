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

vector<vl> mul(vector<vl>& A, vector<vl>& B){
    int n = (int)A.size();
    vector<vl> C(n, vl(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < n; ++k){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

vector<vl> pow(vector<vl> A, int p){
    int n = (int)A.size();
    vector<vl> r(n, vl(n));
    for(int i{0}; i < n; ++i) r[i][i] = 1;
    while(p){
        if(p & 1){
            r = mul(r, A);
        }
        A = mul(A, A);
        p >>= 1;
    }
    return r;
}

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vl> board(n + 2, vl(n + 2));
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        board[a][b]++;
        board[b][a]++;
    }
    int x, y;
    cin >> x >> y;
    for(int i{0}; i < x; ++i){
        int a;
        cin >> a;
        a--;
        board[n][a] = 1;
    }
    for(int i{0}; i < y; ++i){
        int a;
        cin >> a;
        a--;
        board[a][n + 1] = 1;
    }
    board[n + 1][n + 1] = 1;
    cout << (pow(board, k + 2)[n][n + 1] - pow(board, 2)[n][n + 1] + MOD) % MOD;
}
