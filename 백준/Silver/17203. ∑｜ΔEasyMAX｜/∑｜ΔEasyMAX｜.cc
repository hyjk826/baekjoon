// 2022-12-14
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
    int n, q;
    cin >> n >> q;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi A(n);
    for(int i{1}; i < n; ++i){
        A[i] = abs(vec[i - 1] - vec[i]);
        A[i] += A[i - 1];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << A[b - 1] - A[a - 1] << "\n";
    }
}
	
