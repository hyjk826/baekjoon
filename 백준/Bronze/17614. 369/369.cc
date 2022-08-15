// 2022-08-15
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
    int n;
    cin >> n;
    int ans{0};
    for(int i{1}; i <= n; ++i){
        int a = i;
        while(a){
            int k = a % 10;
            if(k == 3 || k == 6 || k == 9){
                ans++;
            }
            a /= 10;
        }
    }
    cout << ans;
}