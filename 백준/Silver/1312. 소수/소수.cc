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
    int a, b, n;
    cin >> a >> b >> n;
    for(int i{0}; i < n; ++i){
        a %= b;
        a *= 10;
        if(i == n - 1){
            cout << a / b;
            return 0;
        }
    }
}

