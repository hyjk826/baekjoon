// 2023-01-18
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
    int x, y;
    cin >> x >> y;
    int a;
    cin >> a;
    vi A(a);
    for(int i{0}; i < a; ++i){
        cin >> A[i];
    }
    int dp[21][21][20];
    memset(dp, -1, sizeof(dp));
    function<int(int,int,int)> f = [&](int q, int w, int e){
        if(e >= a) return 0;
        if(dp[q][w][e] != -1) return dp[q][w][e];
        int& ret = dp[q][w][e];
        ret = MAX;
        ret = min(ret, abs(A[e] - q) + f(A[e], w, e + 1));
        ret = min(ret, abs(A[e] - w) + f(q, A[e], e + 1));
        return ret;
    };
    cout << f(x, y, 0);
}
