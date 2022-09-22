// 2022-09-21
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
    int ans{0};
    if(s.size() != t.size()){
        cout << 0;
        return 0;
    }
    for(int i{0}; i < (int)t.size(); ++i){
        if(s[i] == t[i] && s[i] == '8'){
            ans++;
        }
        else if(s[i] != t[i]) break;
    }
    cout << ans;
}
	

