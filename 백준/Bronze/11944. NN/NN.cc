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
    int a, b;
    cin >> a >> b;
    string ans;
    for(int i{0}; i < a; ++i){
        ans += to_string(a);
    }
    if(ans.size() > b) ans = ans.substr(0, b);
    cout << ans;
}