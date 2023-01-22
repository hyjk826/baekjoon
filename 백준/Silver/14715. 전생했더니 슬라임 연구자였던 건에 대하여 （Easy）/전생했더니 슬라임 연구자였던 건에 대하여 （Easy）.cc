// 2023-01-22
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
    int n;
    cin >> n;
    int cnt{0};
    for(int i{2}; i * i <= n; ++i){
        while(n % i == 0){
            n /= i;
            cnt++;
        }
    }
    if(n != 1) cnt++;
    int ans{0};
    while(cnt != 1){
        cnt = (cnt + 1) / 2;
        ans++;
    }
    cout << ans;
}
