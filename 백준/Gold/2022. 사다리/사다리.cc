// 2022-12-12
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
    double x, y, c;
    cin >> x >> y >> c;
    double lo = 0.0;
    double hi = min(x, y);
    cout << fixed << setprecision(20);
    for(int i{0}; i < 100000; ++i){
        double mid = (lo + hi) / 2;
        double a = sqrt(x * x - mid * mid);
        double b = sqrt(y * y - mid * mid);
        if(1 / a + 1 / b >= 1 / c) hi = mid;
        else lo = mid;
    }
    cout << hi;
}
	
