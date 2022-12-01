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
	ll n;
    cin >> n;
    vl A;
    for(ll i{2}; i * i <= n; ++i){
        while(n % i == 0){
            n /= i;
            A.push_back(i);
        }
    }
    if(n != 1) A.push_back(n);
    if(A.size() <= 1) cout << -1;
    else{
        vl ans;
        ll k = 1;
        if(A.size() & 1) {
            k = A.back();
            A.pop_back();
        }
        for(int i{0}; i < (int)A.size(); i += 2){
            ans.push_back(A[i] * A[i + 1]);
        }
        ans.back() *= k;
        for(auto& i : ans) cout << i << " ";
    }
}
	
