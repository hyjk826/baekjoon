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
    if(n == 1){
        cout << 2 << "\n"; return;
    }
    if(n & 1){
        cout << 3 << " ";
        for(int i{1}; i <= (n - 1) / 2; ++i){
            cout << i * 2 << " " << 999996 - i * 2 << " ";
        }
    }
    else{
        cout << 3 << " " << 6 << " ";
        for(int i{1}; i <= (n - 2) / 2; ++i){
            cout << 2 * (i + 3) << " " << 999996 - 2 * (i + 3) << " ";
        }
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
