// 2022-11-13
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

bool check_prime(ll n){
    if(n == 0 || n == 1) return 0;
    if(n == 2) return 1;
    for(ll i{2}; i * i <= n; ++i){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(ll i{n};;++i){
            if(check_prime(i)){
                cout << i << "\n";
                break;
            }
        }
    }
}
	

