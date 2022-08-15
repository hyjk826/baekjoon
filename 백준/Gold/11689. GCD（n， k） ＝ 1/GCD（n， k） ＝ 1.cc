// 2022-08-15
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
    ll n;
    cin >> n;
    ll m = n;
    vl A;
    for(ll i{2}; i * i <= m; ++i){
        if(m % i == 0){
            A.push_back(i);
            while(m % i == 0){
                m /= i;
            }
        }
    }
    for(auto& i : A){
        n /= i;
        n *= (i - 1);
    }
    if(m > 1){
        n /= m;
        n *= (m - 1);
    }
    cout << n;
}