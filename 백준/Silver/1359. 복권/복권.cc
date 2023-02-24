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

vector<vi> com(10, vi(10, -1));

int f(int a, int b){
    if(a < b || b < 0 || a < 0) return 0;
    if(com[a][b] != -1) return com[a][b];
    if(a == b || b == 0) return com[a][b] = 1;
    return com[a][b] = f(a - 1, b - 1) + f(a - 1, b);
}

int main(){
	fastio;
    cout << fixed << setprecision(20);
    int n, m, k;
    cin >> n >> m >> k;
    double ans{0};
    for(int i{k}; i <= m; ++i){
        int a = f(m, i) * f(n - m, m - i);
        int b = f(n, m);
        ans += 1.0 * a / b;
    }
    cout << ans;
}
