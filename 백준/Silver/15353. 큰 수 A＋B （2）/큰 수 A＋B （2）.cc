// 2022-08-15
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    vi vec((max(s.size(), t.size())));
    for(int i{0}; i < (int)vec.size(); ++i){
        if(i < (int)s.size()) vec[i] += s[i] - '0';
        if(i < (int)t.size()) vec[i] += t[i] - '0';
    }
    string ans;
    for(int i{0}; i < (int)vec.size(); ++i){
        if(vec[i] >= 10){
            if(i == (int)vec.size() - 1){
                ans += char('0' + vec[i] - 10);
                ans += char('0' + 1);                
                break;
            }
            vec[i] -= 10;
            vec[i + 1]++;
        }
        ans += char('0' + vec[i]);
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}