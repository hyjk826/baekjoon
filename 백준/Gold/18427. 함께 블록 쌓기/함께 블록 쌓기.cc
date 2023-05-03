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
	int n, m, h;
    cin >> n >> m >> h;
    string str;
    getline(cin, str);
    vi dp(h + 1);
    dp[0] = 1;
    for(int i{0}; i < n; ++i){
        getline(cin, str);
        str += ' ';
        string s;
        vi A;
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == ' '){
                A.push_back(stoi(s));
                s.clear();
            }
            else s += str[i];
        }
        sort(A.begin(), A.end());
        for(int j{h}; j >= 0; --j){
            for(auto& k : A){
                if(j + k <= h) {
                    dp[j + k] += dp[j];
                    dp[j + k] %= 10007;
                }
            }
        }
    }
    cout << dp[h];
}
