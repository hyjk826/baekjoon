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
	int n;
    cin >> n;
    string str;
    cin >> str;
    vi ch(52);
    int a{0}, b{0};
    for(int i{0}; i < n; ++i){
        if(str[i] == 'r') a |= (1 << 0);
        if(str[i] == 'o') a |= (1 << 1);
        if(str[i] == 'y') a |= (1 << 2);
        if(str[i] == 'g') a |= (1 << 3);
        if(str[i] == 'b') a |= (1 << 4);
        if(str[i] == 'i') a |= (1 << 5);
        if(str[i] == 'v') a |= (1 << 6);
        if(str[i] == 'R') b |= (1 << 0);
        if(str[i] == 'O') b |= (1 << 1);
        if(str[i] == 'Y') b |= (1 << 2);
        if(str[i] == 'G') b |= (1 << 3);
        if(str[i] == 'B') b |= (1 << 4);
        if(str[i] == 'I') b |= (1 << 5);
        if(str[i] == 'V') b |= (1 << 6);
    }
    if((a == (1 << 7) - 1)&& (b == (1 << 7) - 1)) cout << "YeS\n";
    else if(a == (1 << 7) - 1) cout << "yes\n";
    else if(b == (1 << 7) - 1) cout << "YES\n";
    else cout << "NO!";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
