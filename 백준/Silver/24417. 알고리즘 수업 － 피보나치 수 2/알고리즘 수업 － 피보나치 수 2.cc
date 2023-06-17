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
    int a = 1;
    int b = 1;
    int ans{0};
    for(int i{0}; i < n - 2; ++i){
        int tmp = b;
        b = (a + b) % MOD;
        a = tmp;
    }
    cout << b << " " << n - 2;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
