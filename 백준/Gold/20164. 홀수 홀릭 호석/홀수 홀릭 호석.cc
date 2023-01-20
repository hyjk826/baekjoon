// 2023-01-21
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
    string str;
    cin >> str;
    function<pi(string)> f = [&](string s){
        int cnt{0};
        int mn{MAX};
        int mx{0};
        for(int i{0}; i < (int)s.size(); ++i){
            int a = s[i] - '0';
            if(a & 1) cnt++;
        }
        if(s.size() == 1) return make_pair(cnt, cnt);
        else if(s.size() == 2) {
            string k = to_string(s[0] - '0' + s[1] - '0');
            return make_pair(cnt + f(k).first, cnt + f(k).second);
        }
        else{
            int n = (int)s.size();
            for(int i{1}; i <= n - 2; ++i){
                for(int j{i + 1}; j <= n - 1; ++j){
                    string x = s.substr(0, i);
                    string y = s.substr(i, j - i);
                    string z = s.substr(j);
                    string k = to_string(stoi(x) + stoi(y) + stoi(z));
                    mn = min(mn, cnt + f(k).first);
                    mx = max(mx, cnt + f(k).second);
                }
            }
            return make_pair(mn, mx);
        }
    };
    auto ans = f(str);
    cout << ans.first << " " << ans.second;
}
