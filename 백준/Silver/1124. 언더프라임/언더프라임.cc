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
    vi prime(100001);
    prime[1] = 1;
    for(int i{2}; i <= 100000; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= 100000; j += i){
                prime[j] = 1;
            }
        }
    }
    int a, b;
    cin >> a >> b;
    int ans{0};
    for(int i{a}; i <= b; ++i){
        if(prime[i] == 0) continue;
        int cnt{0};
        int a = i;
        for(int j{2}; j * j <= a; ++j){
            while(a % j == 0){
                cnt++;
                a /= j;                
            }
        }
        if(a != 1) cnt++;
        if(prime[cnt] == 0) {
            ans++;
        }
    }
    cout << ans;
}
	

