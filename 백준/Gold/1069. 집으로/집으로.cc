// 2022-12-11
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
    cout << fixed << setprecision(20);
	int X, Y, D, T;
    cin >> X >> Y >> D >> T;
    double d = sqrt(X * X + Y * Y);
    double ans = d;
    if(T >= D) cout << d;
    else{
        int a = ans / D;
        double b = d - a * D;
        if(a == 0) ans = min({ans, 2.0 * T, D - d + T});
        else ans = min({ans, a * T + b, 1.0 * (a + 1) * T});
        cout << ans;
    }
}
	
