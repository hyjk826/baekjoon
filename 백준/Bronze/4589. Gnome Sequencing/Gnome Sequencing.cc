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
    vi vec(3);
    for(int i{0}; i < 3; ++i) cin >> vec[i];
    for(int i{0}; i < 2; ++i){
        if(is_sorted(vec.begin(), vec.end())){
            cout << "Ordered\n"; return;
        }
        reverse(vec.begin(), vec.end());
    }
    cout << "Unordered\n";
}


int main(){
	fastio;
    cout << "Gnomes:\n";
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
