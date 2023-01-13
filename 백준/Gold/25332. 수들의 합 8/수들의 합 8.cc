// 2023-01-13
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
    vi A(n + 1), B(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> A[i];
        A[i] += A[i - 1];
    }
    for(int i{1}; i <= n; ++i){
        cin >> B[i];
        B[i] += B[i - 1];
    }
    map<int, int> mp;
    for(int i{0}; i <= n; ++i){
        mp[A[i] - B[i]]++;
    }
    ll ans{0};
    for(auto& i : mp){
        ans += 1LL * (i.second - 1) * i.second / 2;
    }
    cout << ans;
}
