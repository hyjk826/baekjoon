// 2023-01-16
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

ll dp[11][101][101][101];

struct st{
    int a, b, c;
};

vector<vl> com(101, vl(101, -1));

ll f(ll a, ll b){
    if(com[a][b] != -1) return com[a][b];
    if(a == b || b == 0) return com[a][b] = 1;
    return com[a][b] = f(a - 1, b - 1) + f(a - 1, b);
}

int main(){
	fastio;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    function<ll(int,int,int,int)> ff = [&](int L, int A, int B, int C){        
        if(A > a || B > b || C > c) return 0LL;
        if(L > n) return 1LL;        
        if(dp[L][A][B][C] != -1) return dp[L][A][B][C];
        ll& ret = dp[L][A][B][C];
        ret = 0;
        int k = L;
        ret += ff(L + 1, A + k, B, C);
        ret += ff(L + 1, A, B + k, C);
        ret += ff(L + 1, A, B, C + k);
        if(L % 2 == 0){
            int k = L / 2;
            ret += ff(L + 1, A + k, B + k, C) * f(2 * k, k);
            ret += ff(L + 1, A + k, B, C + k) * f(2 * k, k);
            ret += ff(L + 1, A, B + k, C + k) * f(2 * k, k);
        }
        if(L % 3 == 0){
            int k = L / 3;
            ret += ff(L + 1, A + k, B + k, C + k) * f(3 * k, k) * f(2 * k, k);
        }
        return ret;
    };
    cout << ff(1, 0, 0, 0);
}