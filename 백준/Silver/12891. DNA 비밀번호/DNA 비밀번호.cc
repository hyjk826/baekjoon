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
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    vi A(n + 1), C(n + 1), G(n + 1), T(n + 1);
    for(int i{0}; i < n; ++i){
        if(str[i] == 'A') A[i + 1]++;
        else if(str[i] == 'C') C[i + 1]++;
        else if(str[i] == 'G') G[i + 1]++;
        else T[i + 1]++;
    }
    for(int i{1}; i <= n; ++i){
        A[i] += A[i - 1];
        C[i] += C[i - 1];
        G[i] += G[i - 1];
        T[i] += T[i - 1];
    }
    int a, c, g, t;
    cin >> a >> c >> g >> t;
    int ans{0};
    for(int i{0}; i <= n - m; ++i){
        bool ok = true;
        ok &= (A[i + m] - A[i] >= a);
        ok &= (C[i + m] - C[i] >= c);
        ok &= (G[i + m] - G[i] >= g);
        ok &= (T[i + m] - T[i] >= t);
        if(ok) ans++;
    }
    cout << ans;
}
