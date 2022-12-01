// 2022-12-01
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


int main() {
	fastio;
	vi prime(200001);
    vi A;
    for(ll i{2}; i <= 200000; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= 200000; j += i) prime[j] = 1;
    }
    for(int i{2}; i <= (int)2e5; ++i){
        if(prime[i] == 0) A.push_back(i);
    }
    int n;
    cin >> n;
    cout << A[n - 1];
}
	
