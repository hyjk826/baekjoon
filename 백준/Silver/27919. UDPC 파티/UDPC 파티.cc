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
    int u, d, p, c;
    u = d = p = c = 0;
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == 'U') u++;
        if(str[i] == 'D') d++;
        if(str[i] == 'P') p++;
        if(str[i] == 'C') c++;
    }
    string ans;
    if(2 * (u + c) - 2 >= d + p) ans += 'U';
    if(d + p >= 1) ans += "DP";
    if(ans.empty()) cout << "C";
    else cout << ans;
}
