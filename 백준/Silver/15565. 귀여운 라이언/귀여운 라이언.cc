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
    int n, k;
    cin >> n >> k;
    vi vec;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a == 1) vec.push_back(i);
    }
    int ans{MAX};
    for(int i{0}; i + k - 1 < (int)vec.size(); ++i){
        ans = min(ans, vec[i + k - 1] - vec[i] + 1);
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	

