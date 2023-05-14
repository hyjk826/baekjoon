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

bool f(string& a, string& b){
    if(a.size() > b.size()) return 1;
    else if(a.size() < b.size()) return 0;
    else{
        for(int i{0}; i < (int)a.size(); ++i){
            if(a[i] > b[i]) return 1;
            else if(a[i] < b[i]) return 0;
        }
    }
    return 1;
}


int main(){
	fastio;
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int p;
    cin >> p;
    vector<string> dp(p + 1);
    for(int i{1}; i <= p; ++i){
        for(int j{0}; j < n; ++j){
            if(i >= vec[j]){
                string k = dp[i - vec[j]];
                k += char('0' + j);
                if(k == "0") continue;
                if(f(k, dp[i])) dp[i] = k;
            }
        }
    }
    if(dp[p].empty()) cout << 0;
    else cout << dp[p];
}
