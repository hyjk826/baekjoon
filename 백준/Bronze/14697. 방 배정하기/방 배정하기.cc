// 2022-07-31
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
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    for(int i{0}; i <= n / a; ++i){
        for(int j{0}; j <= n / b; ++j){
            for(int k{0}; k <= n / c; ++k){
                if(a * i + b * j + c * k == n){
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;
}

