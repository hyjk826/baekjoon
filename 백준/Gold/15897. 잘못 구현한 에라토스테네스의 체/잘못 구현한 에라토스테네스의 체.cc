// 2022-06-20
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n;
    cin >> n;
    ll ans = n;
    int k = n - 1;
    int a;
    for(int i{1}; i <= k; i = a + 1){
        a = k / (k / i);
        ans += (a - i + 1) * (k / i);
    }
    cout << ans;
}