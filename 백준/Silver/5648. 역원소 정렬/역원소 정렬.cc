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

int main() {
	fastio;
    ll n;
    cin >> n;
    vl vec;    
    for(int i{0}; i < n; ++i){
        ll a;
        cin >> a;
        string str = to_string(a);
        reverse(str.begin(), str.end());
        vec.push_back(stoll(str));
    }
    sort(vec.begin(), vec.end());
    for(auto& i : vec) cout << i << "\n";
}
	

