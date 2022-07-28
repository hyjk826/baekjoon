// 2022-07-28
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
    vi A(10), B(10);
    for(int i{0}; i < 10; ++i) cin >> A[i];
    for(int i{0}; i < 10; ++i) cin >> B[i];
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    cout << A[0] + A[1] + A[2] << " " << B[0] + B[1] + B[2];
}

