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
    vi X(n), Y(n);
    for(int i{0}; i < n; ++i){
        cin >> X[i]>> Y[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    cout << (X.back() - X.front()) * (Y.back() - Y.front());
}
