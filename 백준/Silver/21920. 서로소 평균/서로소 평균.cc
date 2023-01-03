// 2023-01-03
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
    function<int(int, int)> gcd = [&](int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    };
    int x;
    cin >> x;
    ll sum{0}, cnt{0};
    for(int i{0}; i < n; ++i){
        if(gcd(x, vec[i]) == 1){
            sum += vec[i];
            cnt++;
        }
    }
    cout << fixed << setprecision(20);
    cout << 1.0 * sum / cnt;
}
