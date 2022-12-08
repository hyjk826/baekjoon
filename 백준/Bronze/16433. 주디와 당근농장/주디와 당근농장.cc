// 2022-12-08
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

int main() {
	fastio;
	int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if((i + j) % 2 == (x + y) % 2) cout << "v";
            else cout << ".";
        }
        cout << "\n";
    }
}
	
