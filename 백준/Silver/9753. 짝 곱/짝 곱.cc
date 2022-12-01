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
	vi prime((int)1e5 + 1);
    for(ll i{2}; i <= (int)1e5; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= (int)1e5; j += i){
            prime[j] = 1;
        }
    }
    vi A;
    for(int i{2}; i <= (int)1e5; ++i){
        if(prime[i] == 0) A.push_back(i);
    }
    vi B;
    for(int i{0}; i < (int)A.size(); ++i){
        for(int j{i + 1}; j < (int)A.size(); ++j){
            if(1LL * A[i] * A[j] > (int)1e5 + 1) break; 
            B.push_back(A[i] * A[j]);
        }
    }
    sort(B.begin(), B.end());
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << *lower_bound(B.begin(), B.end(), n) << "\n";
    }
}
	
