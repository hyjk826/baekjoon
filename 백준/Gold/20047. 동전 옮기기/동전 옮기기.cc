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
    string s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    string ss;
    for(int i{0}; i < (int)s.size(); ++i){
        if(i == a || i == b) continue;
        ss += s[i];
    }
    vector<vi> dp(n, vi(3, -1));
    function<int(int,int,int)> f = [&](int x, int y, int idx){       
        if(x == n){
            if(y == 2) return 1;                
            else return 0;            
        }
        if(dp[x][y] != -1) return dp[x][y];
        int& ret = dp[x][y];
        ret = 0;
        if(y == 0){
            ret |= (s[a] == t[x]) && f(x + 1, 1, idx);
            if(idx < (int)ss.size()) ret |= (ss[idx] == t[x]) && f(x + 1, 0, idx + 1);
            
        }
        else if(y == 1){
            ret |= (s[b] == t[x]) && f(x + 1, 2, idx);
            if(idx < (int)ss.size()) ret |= (ss[idx] == t[x]) && f(x + 1, 1, idx + 1);            
        }
        else{
            if(idx < (int)ss.size()) ret |= (ss[idx] == t[x]) && f(x + 1, 2, idx + 1);            
        }
        return ret;
    };
    if(f(0, 0, 0)) cout << "YES";
    else cout << "NO";
}
