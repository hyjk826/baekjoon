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
    int a, b;
    cin >> a >> b;
    if(a <= 1023) cout << "No thanks";
    else{
        int k = a - 1023;
        if((k & b) == k) cout << "Thanks";
        else cout << "Impossible";
    }
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
