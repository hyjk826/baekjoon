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


ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main(){
	fastio;
    ll a, b;
    cin >> a >> b;
    if(a == b) {
        cout << 1; return 0;
    }
    ll k = abs(a - b);
    vl div;
    for(int i{1}; i * i <= k; ++i){
        if(k % i == 0) {
            if(i * i == k) div.push_back(i);
            else{
                div.push_back(i);
                div.push_back(k / i);
            }
        }
    }
    vpl A;
    for(auto& i : div){
        int k = i - a % i;
        A.push_back({lcm(a + k, b + k), k});
    }
    sort(A.begin(), A.end());
    cout << A.front().second;
}
