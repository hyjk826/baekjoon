// 2022-08-14
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	fastio;
    int n;
    cin >> n;
    int g{0};
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        g = gcd(g, a);
    }
    vi ans;
    for(int i{1}; i * i <= g; ++i){
        if(g % i == 0){
            if(i * i == g) ans.push_back(i);
            else{
                ans.push_back(i);
                ans.push_back(g / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << "\n";
}

