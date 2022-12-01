// 2022-12-01
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
	int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(b - a >= c) cout << 2 * (a + c);
    else {
        c -= (b - a);
        if(c & 1) c--;
        cout << b * 2 + c;
    }
}
	
