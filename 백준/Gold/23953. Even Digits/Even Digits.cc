// 2023-01-17
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
    int idx{-1};
    for(int i{0}; i < (int)str.size(); ++i){
        int k = str[i] - '0';
        if(k & 1){
            idx = i;
            break;
        }
    }
    if(idx == -1) cout << 0 << "\n";
    else{
        string s = str.substr(idx);
        string up, down;
        up = down = s;
        up[0]++;
        down[0]--;
        for(int i{1}; i < (int)up.size(); ++i){
            up[i] = '0';
            down[i] = '8';
        }
        if(up[0] == '9' + 1) {
            up[0] = '0';
            up = "2" + up;
        }
        if(down.size() >= 2 && down[0] == '0') down.erase(down.begin());
        cout << min(stoll(up) - stoll(s), stoll(s) - stoll(down)) << "\n";
    }
}

int main() {
	fastio;	
	int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        cout << "Case #" << T << ": ";
        solve();
    }
}
	
