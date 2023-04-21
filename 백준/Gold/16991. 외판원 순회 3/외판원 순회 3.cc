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

double dp[16][1 << 16];


int main(){
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        for(int j{0}; j < (1 << n); ++j){
            dp[i][j] = -2;
        }
    }
    function<double(int,int)> dist = [&](int a, int b){
        int x = vec[a].first - vec[b].first;
        int y = vec[a].second - vec[b].second;
        return sqrt(x * x + y * y);
    };
    function<double(int,int)> f = [&](int a, int b){
        if(dp[a][b] > -1) return dp[a][b];
        if(b == (1 << n) - 1){
            return dp[a][b] = dist(0, a);
        }
        double mn{MAX};
        for(int i{0}; i < n; ++i){
            if(b & (1 << i)) continue;
            mn = min(mn, dist(a, i) + f(i, b | (1 << i)));
        }
        return dp[a][b] = mn;
    };
    cout << fixed << setprecision(20);
    cout << f(0, 1);
}
