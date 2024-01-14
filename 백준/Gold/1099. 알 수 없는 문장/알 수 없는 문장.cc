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
	string str;
    cin >> str;
    int n;
    cin >> n;
    vs vec(n);
    for(auto& i : vec) cin >> i;
    int m = (int)str.size();
    vi dp(m, -1);
    function<int(int)> f = [&](int a){
        if(a == m) return 0;
        int& ret = dp[a];
        if(ret != -1) return ret;
        ret = MAX;
        for(int i{0}; i < n; ++i){
            if(a + (int)vec[i].size() - 1 >= m) continue;
            vi cnt(26);
            for(int j{a}; j < a + (int)vec[i].size(); ++j){
                cnt[str[j] - 'a']++;
                cnt[vec[i][j - a] - 'a']--;                
            }
            bool ok = true;
            for(int j{0}; j < 26; ++j){
                ok &= (cnt[j] == 0);
            }
            if(ok){
                int b{0};
                for(int j{a}; j < a + (int)vec[i].size(); ++j){
                    b += (str[j] != vec[i][j - a]);                  
                }      
                ret = min(ret, b + f(a + (int)vec[i].size()));
            }
        }
        return ret;
    };
    int ans = f(0);
    if(ans == MAX) ans = -1;
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}