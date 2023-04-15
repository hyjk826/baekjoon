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
    int k;
    cin >> k;
    vi dp(k + 1, -1);
    dp[k] = 0;
    vector<vi> vec(k + 1);
    vector<vi> div(k);
    for(int i{1}; i < k; ++i){
        for(int j{i}; j < k; j += i){
            div[j].push_back(i);
        }
    }
    function<int(int)> f = [&](int a){
        if(a > k) return 1;
        if(dp[a] != -1) return dp[a];
        bool ok = false;
        for(auto& i : div[a]){
            ok |= (f(i + a) == 0);
        }
        return dp[a] = ok;
    };
    if(f(1)) cout << "Kali";
    else cout << "Ringo";
}
