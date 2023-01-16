// 2023-01-16
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

int main(){
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    bool ok = true;
    int sum{0};
    for(int i{0}; i < n - 1; ++i){
        sum += vec[i];
        ok &= (sum >= (i + 1) * i / 2);
    }
    sum += vec[n - 1];
    ok &= (sum == n * (n - 1) / 2);
    if(ok) cout << 1;
    else cout << -1;
}