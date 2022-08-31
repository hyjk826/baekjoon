// 2022-08-31
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
    string str;
    cin >> str;
    string ans;
    reverse(str.begin(), str.end());
    for(int i{0}; i < (int)str.size(); i += 3){
        int sum{0};
        for(int j{i}; j < min(i + 3, (int)str.size()); ++j){
            sum += (str[j] - '0') * (1 << (j - i));
        }
        ans += char('0' + sum);
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

