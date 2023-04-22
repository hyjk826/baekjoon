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

int floyd[201][201];
int A[20000], B[20000], C[20000];


int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            floyd[i][j] = (int)1e9;
        }
        floyd[i][i] = 0;
    }
    for(int i{0}; i < m; ++i){
        cin >> A[i] >> B[i] >> C[i];
        floyd[A[i]][B[i]] = min(floyd[A[i]][B[i]], C[i]);
        floyd[B[i]][A[i]] = min(floyd[A[i]][B[i]], C[i]);
    }
    for(int k{1}; k <= n; ++k){
        for(int i{1}; i <= n; ++i){
            for(int j{1}; j <= n; ++j){
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }
    int mn{MAX};
    for(int i{1}; i <= n; ++i){
        int mx{0};
        for(int j{0}; j < m; ++j){
            mx = max(mx, floyd[i][A[j]] + floyd[i][B[j]] + C[j]);
        }
        mn = min(mn, mx);
    }
    cout << mn / 2 << ".";
    if(mn & 1) cout << 5;
    else cout << 0;
}
