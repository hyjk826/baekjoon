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

int dp[30][30][30][450]{};

int main(){
	fastio;
    int n, k;
    cin >> n >> k;
    string ans;
    function<void(int,int,int,int)> f = [&](int a, int b, int c, int d){
        if(d < 0) return;
        if(a == n){
            if(d == 0){
                cout << ans; exit(0);
            }
            else return;
        }
        if(dp[a][b][c][d]) return;
        dp[a][b][c][d] = 1;
        ans += 'A';
        f(a + 1, b + 1, c, d);
        ans.pop_back();
        ans += 'B';
        f(a + 1, b, c + 1, d - b);
        ans.pop_back();
        ans += 'C';
        f(a + 1, b, c, d - b - c);
        ans.pop_back();
    };
    f(0, 0, 0, k);
    cout << -1;
}