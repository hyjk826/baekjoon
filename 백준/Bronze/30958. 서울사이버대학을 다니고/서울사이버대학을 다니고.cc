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
    getline(cin, str);
    getline(cin, str);
    vi ch(52);
    for(int i{0}; i < n; ++i){
        if(str[i] >= 'a' && str[i] <= 'z') ch[str[i] - 'a']++;
        if(str[i] >= 'A' && str[i] <= 'Z') ch[str[i] - 'A']++;
    }
    cout << *max_element(ch.begin(), ch.end()) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
