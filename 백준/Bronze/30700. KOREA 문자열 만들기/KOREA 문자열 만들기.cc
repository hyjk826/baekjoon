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

string s = "KOREA";

void solve(){
	string str;
    cin >> str;
    int ans{0};
    int idx{0};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == s[idx]){
            idx = (idx + 1) % 5;
            ans++;
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
