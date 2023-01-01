// 2023-01-01
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

#define ull __int128
// #define ull unsigned long long 

vl prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; 
// vl prime = {2, 7, 61};

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
        if(n == prime[i]) return 1;
        if(n > 40 && !miller_rabin(n, prime[i])) return 0;
    }
    if(n <= 40) return 0;
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

int main(){
	fastio;
    cout << fixed << setprecision(6);
    vector<unsigned long long> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    while(fibo.back() <= LLONG_MAX){
        fibo.push_back(fibo.back() + fibo[(int)fibo.size() - 2]);
    }
    vector<vl> A;
    A.push_back({});
    A.push_back({});
    A.push_back({});
    for(int i{3}; i < (int)fibo.size(); ++i){
        if(fibo[i] > LLONG_MAX) break;
        vl B;
        pollard_rho(fibo[i], B);
        sort(B.begin(), B.end());
        A.push_back(B);
    }
    ll a, b;
    while(cin >> hex >> a >> b){
        if(a >= b) break;
        cout << "Range " << a << " to " << b << ":\n";
        int l = lower_bound(fibo.begin(), fibo.end(), a) - fibo.begin();
        int r = upper_bound(fibo.begin(), fibo.end(), b) - fibo.begin();
        if(l == r){
            cout << "No Fibonacci numbers in the range\n";
        }
        else{
            for(int i{l}; i < r; ++i){
                cout << "Fib(" << i << ") = " << fibo[i] << ", ";
                if(i == 0) cout << "lg does not exist\n";
                else cout << "lg is " << log2(fibo[i]) << "\n";
                if(A[i].empty()) cout << "No prime factors\n";
                else{
                    cout << "Prime factors: ";
                    for(auto& j : A[i]){
                        cout << j << " ";
                    }
                    cout << '\n';
                }
            }
        }
        cout << "\n";
    }
}
