// 2022-12-20
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


vi prime((int)1e6);

int main(){
	fastio;
	int n;
    cin >> n;
    prime[1] = 1;
    for(ll i{2}; i <= (int)1e6; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= (int)1e6; j += i){
            prime[j] = 1;
        }
    }
    vector<vi> dp(n + 1, vi(n + 1, -1));
    function<int(int, int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        if(a == n && b == n){
            if(prime[stoi(to_string(a) + to_string(b))]) return dp[a][b] = 0;
            else return dp[a][b] = 1;
        }
        else{
            int k{0};
            if(prime[stoi(to_string(a) + to_string(b))] == 0) k++;
            int mx{0};
            if(a + 1 <= n) mx = max(mx, f(a + 1, b));
            if(b + 1 <= n) mx = max(mx, f(a, b + 1));
            return dp[a][b] = k + mx;
        }
    };
    cout << f(1, 1) - 1;
}
	
