// 2022-11-12
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

typedef unsigned long long ull;

ll prime[3] = {2, 7, 61};

ull modpow(ull a, ull b, ull mod){
    ull ans{1};
    while(b){
        if(b & 1){
            ans = (ans * a) % mod;            
        }
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

bool miller_rabin(ull n, ull a){
    if(a % n == 0) return 1;
    ull k = n - 1;
    while(k % 2 == 0){
        if(modpow(a, k, n) == n - 1) return 1;
        k /= 2;
    }
    ull temp = modpow(a, k, n);
    return (temp == 1 || temp == n - 1);
}

bool check_prime(ull n){
    for(int i{0}; i < 3; ++i){
        if(!miller_rabin(n, prime[i])) return 0;
    }
    return 1;
}




int main() {
	fastio;
    int n;
    cin >> n;
    int ans{0};
    for(int i{0}; i < n; ++i){
        ull a;
        cin >> a;
        a *= 2;
        a++;
        if(check_prime(a)) ans++;
    }
    cout << ans++;
}
	

