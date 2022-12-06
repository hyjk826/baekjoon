// 2022-12-07
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
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int ans{0};
    vi A(n);
    for(int i{0}; i < n; ++i){
        if(A[i] == vec[i]) continue;
        ans++;
        for(int j{i}; j < min(n, i + 3); ++j){
            A[j] ^= 1;
        }
    }
    cout << ans;
}
	
