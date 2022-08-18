// 2022-08-18
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

vector<vl> com(2001, vl(2001, -1));
ll n, k, m;

ll f(int a, int b){
    if(a < b) return 0;
    if(com[a][b] != -1) return com[a][b];
    if(a == b || b == 0) return com[a][b] = 1;
    com[a][b] = 0;
    return com[a][b] = (f(a - 1, b - 1) + f(a - 1, b)) % m;;
}

int main() {
	fastio;
    cin >> n >> k >> m;
    vi A, B;
    while(n){
        A.push_back(n % m);
        n /= m;
    }
    while(k){
        B.push_back(k % m);
        k /= m;
    }
    ll ans{1};
    for(int i{0}; i < (int)min(A.size(), B.size()); ++i){
        ans *= f(A[i], B[i]);
        ans %= m;
    }
    cout << ans;
}