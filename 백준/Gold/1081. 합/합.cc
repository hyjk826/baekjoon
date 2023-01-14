// 2022-09-06
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

ll ff(int n){
    if(n <= 0) return 0;
    ll ret{0};
    vl A(10);
    int l{1};
    int k{1};
    function<void(int, int)> f = [&](int k, int cnt){
        while(k){
            A[k % 10] += cnt;
            k /= 10;
        }
    };
    while(l <= n){
        while(n % 10 != 9 && l <= n){
            f(n, k);
            n--;
        }
        if(l > n) break;
        while(l % 10 != 0 && l <= n){
            f(l, k);
            l++;
        }
        l /= 10;
        n /= 10;
        for(int i{0}; i < 10; ++i){
            A[i] += 1LL * (n - l + 1) * k;
        }
        k *= 10;
    }
    for(int i{1}; i < 10; ++i){
        ret += 1LL * A[i] * i;
    }
    return ret;
}

int main() {
	fastio;
    int a, b;
    cin >> a >> b;
    cout << ff(b) - ff(a - 1);
}
	

