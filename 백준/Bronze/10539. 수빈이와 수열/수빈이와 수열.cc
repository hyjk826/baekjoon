// 2022-08-14
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
    vi B(n);
    int sum{0};
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }
    for(int i{0}; i < n; ++i){
        cout << (i + 1) * B[i] - sum << " ";
        sum += (i + 1) * B[i] - sum;
    }
}

