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

void solve(){
    int n;
    cin >> n;
    vs vec(n);
    for(auto& i : vec) cin >> i;
    vector<vi> dp((1 << n), vi(6, -1));
    string vowel = "AEIOU";
    function<int(int,int)> f = [&](int a, int b){
        if(dp[a][b] != -1) return dp[a][b];
        int& ret = dp[a][b];
        dp[a][b] = 0;
        for(int i{0}; i < n; ++i){
            if((a >> i) & 1) continue;
            if(b) if(vowel.find(vec[i].front()) + 1 != b) continue;
            ret = max(ret, f(a | (1 << i), vowel.find(vec[i].back()) + 1) + (int)vec[i].size());
        }
        return ret;
    };
    cout << f(0, 0);
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
