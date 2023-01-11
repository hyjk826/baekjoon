// 2023-01-11
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
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int mx{0};
    function<int(int,int)> f = [&](int x, int y){
        int n = max(abs(x), abs(y));
        int diff = 2 * n;
        int k = (2 * n + 1) * (2 * n + 1);
        if(x == n) return k - (n - y);
        k -= diff;
        if(y == -n) return k - (n - x);
        k -= diff;
        if(x == -n) return k - (n + y);
        k -= diff;
        return k - (n + x);
    };
    for(int i{r1}; i <= r2; ++i){
        for(int j{c1}; j <= c2; ++j){
            mx = max(mx, f(i, j));
        }
    }
    int cnt{0};
    while(mx){
        mx /= 10;
        cnt++;
    }
    for(int i{r1}; i <= r2; ++i){
        for(int j{c1}; j <= c2; ++j){
            cout << setw(cnt) << f(i, j) << " ";
        }
        cout << "\n";
    }
}
