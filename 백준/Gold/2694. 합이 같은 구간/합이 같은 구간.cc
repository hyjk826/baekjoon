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

// #define ull __int128
#define ull unsigned long long 

// vl prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; 
vl prime = {2, 7, 61};

ull modpow(ull a, ull b, ull mod){
    ull ans{1};
    while(b){
        if(b & 1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
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
    for(int i{0}; i < (int)prime.size(); ++i){
        // if(n == prime[i]) return 1;
        // if(n > 40 && !miller_rabin(n, prime[i])) return 0;
        if(!miller_rabin(n, prime[i])) return 0;
    }
    // if(n <= 40) return 0;
    return 1;
}

ull mul(ull x, ull y, ull mod) {
    x %= mod; 
    y %= mod; 
    return x * y % mod;
}

ull gcd(ull a, ull b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void pollard_rho(ll n, vector<ll>& v) {
	if (n == 1) return;
	if (n % 2 == 0) {
		v.push_back(2);
		pollard_rho(n / 2, v);
		return;
	}
	if (check_prime(n)) {
		v.push_back(n);
		return;
	}
	ll a, b, c, g = n;
    auto f = [&](ll x) {
        return (c + mul(x, x, n)) % n;
    };
    do {
        if (g == n) {
            a = b = rand() % (n - 2) + 2;
            c = rand() % 20 + 1;
        }
        a = f(a);
        b = f(f(b));
        g = gcd(abs(a - b), n);
    } while (g == 1);
	pollard_rho(g, v);
	pollard_rho(n / g, v);
}

vl divisor(int n){
    vl v;
    pollard_rho(n, v);
    unordered_map<int, int> mp;
    for(auto& i : v) mp[i]++;
    vl ret;
    function<void(unordered_map<int,int>::iterator, ll)> f = [&](unordered_map<int,int>::iterator it, ll sum){
        if(it == mp.end()){
            ret.push_back(sum);
        }
        else{
            f(next(it), sum);
            for(int i{0}; i < it->second; ++i){
                sum *= it->first;
                f(next(it), sum);
            }
        }
    };
    f(mp.begin(), 1);
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        int sum{0};
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
            sum += vec[i];
        }
        vl div = divisor(sum);
        for(auto& i : div){
            sum = 0;
            for(int j{0}; j < n; ++j){
                sum += vec[j];
                if(sum == i){
                    sum = 0;
                }
                else if(sum > i){
                    sum = MAX; break;
                }                
            }
            if(sum != MAX){
                cout << i << "\n"; break;
            }
        }
    }
}
