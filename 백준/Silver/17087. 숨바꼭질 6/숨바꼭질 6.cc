// 2022-08-31
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	fastio;
    int n, m;
    cin >> n >> m;
    vi vec;
    vec.push_back(m);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    int ans{0};
    sort(vec.begin(), vec.end());
    for(int i{0}; i < n; ++i){
        ans = gcd(ans, vec[i + 1] - vec[i]);
    }
    cout << ans;
}

