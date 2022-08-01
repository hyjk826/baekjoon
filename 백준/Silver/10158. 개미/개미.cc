// 2022-08-01
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int w, h;
    cin >> h >> w;
    int x, y;
    cin >> x >> y;
    int t;
    cin >> t;
    int a = (x + t) % (2 * h);
    int b = (y + t) % (2 * w);
    if(a > h) a = h - (a - h);
    if(b > w) b = w - (b - w);
    cout << a << " " << b;
}

