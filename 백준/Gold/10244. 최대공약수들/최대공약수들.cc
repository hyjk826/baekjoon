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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        vi vec(n);
        int mx{0};
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
            mx = max(mx, vec[i]);
        }
        int ans{0};
        for(int i{1}; i <= mx; ++i){
            int k{0};
            for(int j{0}; j < n; ++j){
                if(vec[j] % i != 0){
                    k = 0;
                }
                else{
                    k = gcd(k, vec[j] / i);
                }
                if(k == 1){
                    ans++; break;
                }
            }
        }
        cout << ans << "\n";
    }
}
