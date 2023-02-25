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
    double t;
    cin >> n >> t;
    vl X(n), V(n);
    for(int i{0}; i < n; ++i){
        cin >> X[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> V[i];
    }
    double l{-1e18}, r{1e18};
    for(int i{0}; i < n; ++i){
        l = max(l, X[i] - V[i] * t);
        r = min(r, X[i] + V[i] * t);
    }
    if(r - l > -1e-08) cout << 1;
    else cout << 0;
}
