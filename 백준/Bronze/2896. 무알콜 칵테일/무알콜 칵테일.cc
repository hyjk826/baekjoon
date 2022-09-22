// 2022-09-21
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
    cout << fixed << setprecision(10);
    vector<double> A(3), B(3);
    for(int i{0}; i < 3; ++i) cin >> A[i];
    for(int i{0}; i < 3; ++i) cin >> B[i];
    double d{MAX};
    for(int i{0}; i < 3; ++i){
        d = min(d, 1.0 * A[i] / B[i]);
    }
    for(int i{0}; i < 3; ++i){
        cout << A[i] - d * B[i] << " ";
    }
}
	

