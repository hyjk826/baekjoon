// 2022-09-06
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

int f(vi& vec){
    int sum{0};
    sort(vec.begin(), vec.end());
    if(vec[0] == vec[3]) return 50000 + vec[0] * 5000;
    if(vec[0] == vec[2] || vec[1] == vec[3]) return 10000 + vec[1] * 1000;
    if(vec[0] == vec[1] && vec[2] == vec[3]) return 2000 + 500 * (vec[1] + vec[2]);
    if(vec[0] == vec[1]) return 1000 + vec[0] * 100;
    if(vec[2] == vec[3]) return 1000 + vec[2] * 100;
    if(vec[1] == vec[2]) return 1000 + vec[1] * 100;
    return vec[3] * 100;
}

int main() {
	fastio;
    int n;
    cin >> n;  
    int ans{0};
    for(int i{0}; i < n; ++i){
        vi vec(4);
        for(int j{0}; j < 4; ++j){
            cin >> vec[j];
        }
        ans = max(ans, f(vec));
    }
    cout << ans;
}
	

