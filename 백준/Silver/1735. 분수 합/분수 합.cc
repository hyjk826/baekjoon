// 2022-07-23
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a * d + b * c;
    int y = b * d;
    int g = __gcd(x, y);
    cout << x / g << " " << y / g;
}

