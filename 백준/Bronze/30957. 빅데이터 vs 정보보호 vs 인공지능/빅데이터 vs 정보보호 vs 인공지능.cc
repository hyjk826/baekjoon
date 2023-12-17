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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

void solve(){
	int n;
    cin >> n;
    string str;
    cin >> str;
    int b, s, a;
    b = s = a = 0;
    for(int i{0}; i < n; ++i){
        if(str[i] == 'B') b++;
        else if(str[i] == 'S') s++;
        else if(str[i] == 'A') a++;
    }
    string ans;
    int mx = max({b, s, a});
    if(mx == b) ans += 'B';
    if(mx == s) ans += 'S';
    if(mx == a) ans += 'A';
    if(ans.size() == 3) ans = "SCU";
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
