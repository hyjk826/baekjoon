// 2022-09-01
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
    vi prime(1000001);
    prime[1] = 1;
    for(int i{2}; i <= (int)1e6; ++i){
        if(prime[i] == 0){
            for(int j{i * 2}; j <= (int)1e6; j += i){
                prime[j] = 1;
            }
        }
    }
    vi vec;
    for(int i{1}; i <= (int)1e6; ++i){
        if(prime[i] == 0) vec.push_back(i);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans{0};
        for(auto& i : vec){
            int a = n - i;
            if(i > n - i) break;
            if(prime[a] == 0) ans++;
        }
        cout << ans << '\n';
    }
}

