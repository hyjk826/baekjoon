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
    int a, b, c;
    cin >> a >> b >> c;
    if(c & 1) a ^= b;
    cout << a;
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
