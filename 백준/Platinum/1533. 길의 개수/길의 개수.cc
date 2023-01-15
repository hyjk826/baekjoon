// 2022-12-09
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
#define MOD 1000003
using namespace std;

int n;
int sum;

vector<vl> mul(vector<vl>& A, vector<vl>& B){
    vector<vl> C(sum, vl(sum));
    for(int i{0}; i < sum; ++i){
        for(int j{0}; j < sum; ++j){
            for(int k{0}; k < sum; ++k){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

vector<vl> pow(vector<vl> A, int p){
    vector<vl> r(sum, vl(sum));
    for(int i{0}; i < sum; ++i) r[i][i] = 1;
    while(p){
        if(p & 1){
            r = mul(r, A);
        }
        A = mul(A, A);
        p >>= 1;
    }
    return r;
}


int main() {
	fastio;
    int n, s, t, k;
    cin >> n >> s >> t >> k;
    s--;
    t--;
    sum = 5 * n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    vector<vl> A(5 * n, vl(5 * n));
    for(int i{0}; i < n; ++i){
        for(int j{1}; j < 5; ++j){
            A[i * 5 + j][i * 5 + j - 1] = 1;
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(board[i][j] == 0) continue;
            if(board[i][j] == 1) A[i * 5][j * 5] = 1;
            else A[i * 5][j * 5 + board[i][j] - 1] = 1;
        }
    }
    cout <<  pow(A, k)[s * 5][t * 5] << "\n";
}
	
