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
    sort(vec.begin(), vec.end());
    if(vec[0] + vec[1] > vec[2]){
        if(vec[0] == vec[1] && vec[1] == vec[2]) cout << "equilateral\n";
        else if(vec[0] == vec[1] || vec[1] == vec[2]) cout << "isosceles\n";
        else cout << "scalene\n";
    }
    else cout << "invalid!\n";
}

int main(){
	fastio;
	int T;
	cin >> T;
	for(int i{0}; i < T; ++i){
        cout << "Case #" << i + 1 << ": ";
		solve();
	}
}
