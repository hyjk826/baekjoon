// 2022-11-30
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
	int n, k;
    cin >> n >> k;
    vi prime(n + 1);
    for(int i{2}; i <= n; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= n; j += i){
                prime[j] = i;
            }
        }
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        if(prime[i] == 0){
            if(i <= k) ans++;
        }
        else{
            if(prime[i] <= k) ans++;
        }
    }
    cout << ans;
}
	

// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 2 5 3 7 