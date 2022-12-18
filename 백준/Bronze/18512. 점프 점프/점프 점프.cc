// 2022-12-18
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

int main(){
	fastio;
	int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans{MAX};
    for(int i{0}; i <= 1000; ++i){
        for(int j{0}; j <= 1000; ++j){
            if(c + a * i == d + b * j){
                ans = min(ans, c + a * i);
            }
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	
