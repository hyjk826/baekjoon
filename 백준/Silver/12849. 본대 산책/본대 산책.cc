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
    vector<vl> C(8, vl(8));
    for(int i{0}; i < 8; ++i){
        for(int j{0}; j < 8; ++j){
            for(int k{0}; k < 8; ++k){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}

vector<vl> pow(vector<vl> A, int p){
    vector<vl> r(8, vl(8));
    for(int i{0}; i < 8; ++i) r[i][i] = 1;

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
    vector<vl> A = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
    };
    int p;
    cin >> p;
    cout << pow(A, p)[0][0];
}
	
