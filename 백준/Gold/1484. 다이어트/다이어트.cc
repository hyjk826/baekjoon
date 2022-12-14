// 2022-12-14
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
    int k;
    cin >> k;
    vi ans;
    for(int i{1}; i * i < k; ++i){
        if(k % i == 0){
            int a = k / i;
            int b = i;
            if(a % 2 == b % 2){
                ans.push_back((a + b) / 2);
            }
        }
    }
    if(ans.empty()) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for(auto& i : ans) cout << i << "\n";
    }
}
	
