// 2022-08-15
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
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b + c) cout << a << "=" << b << "+" << c << "\n";
    else if(a == b - c) cout << a << "=" << b << "-" << c << "\n";
    else if(a == b / c && b % c == 0) cout << a << "=" << b << "/" << c << "\n";
    else if(a + b == c) cout << a << "+" << b << "=" << c << "\n";
    else if(a - b == c) cout << a << "-" << b << "=" << c << "\n";
    else if(a / b == c && a % b == 0) cout << a << "/" << b << "=" << c << "\n";
    else if(a * b == c) cout << a << "*" << b << "=" << c << "\n";
}