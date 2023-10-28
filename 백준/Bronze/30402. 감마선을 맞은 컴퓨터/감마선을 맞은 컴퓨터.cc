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
	for(int i{0}; i < 15; ++i){
        for(int j{0}; j < 15; ++j){
            char c;
            cin >> c;
            if(c == 'w') {
                cout << "chunbae"; return;
            }
            else if(c == 'b') {
                cout << "nabi"; return;
            }
            else if(c == 'g') {
                cout << "yeongcheol";
                return;
            }
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
