// 2022-09-16
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
    int n;
    cin >> n;
    cout << n * (n - 1) / 2 << "\n";
    int k{1};
    for(int i{0}; i < n; ++i){
        cout << k << " ";
        k *= 2;
    }
    cout << "\n";
    cout << n - 1 << "\n";
    for(int i{1}; i <= n; ++i){
        cout << i << " ";
    }
}
	

