// 2022-09-14
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi X(n), Y(n);
        for(int i{0}; i < n; ++i){
            cin >> X[i] >> Y[i];
        }
        double mn{MAX};
        for(int i{0}; i < (1 << n); ++i){
            if(__builtin_popcount(i) == n / 2){
                int a{0}, b{0}, c{0}, d{0};;
                for(int j{0}; j < n; ++j){
                    if((i >> j) & 1){
                        a += X[j];
                        c += Y[j];
                    }
                    else{
                        b += X[j];
                        d += Y[j];
                    }
                }
                int x = abs(a - b);
                int y = abs(c - d);
                double k = sqrt(1LL * x * x + 1LL * y * y);
                mn = min(mn, k);
            }
        }
        cout << fixed << setprecision(10);
        cout << mn << "\n";
    }
}
	

