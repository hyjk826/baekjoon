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
    int l, r;
    cin >> l >> r;
    vi prime(33333);
    prime[1] = 1;
    for(ll i{2}; i * i <= (int)1e9; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j * j <= (int)1e9; j += i){
            prime[j] = 1;
        }
    }
    vi A;
    for(int i{l}; i <= r; ++i) A.push_back(i);
    vi cnt(r - l + 1);
    for(int i{2}; i * i <= r; ++i){
        if(prime[i]) continue;
        int st = l;
        if(l % i != 0) st += i - l % i;
        for(int j{st}; j <= r; j += i){
            while(A[j - l] % i == 0){
                A[j - l] /= i;
                cnt[j - l]++;
            }
        }
    }
    int ans{0};
    for(int i{0}; i <= r - l; ++i){
        if(A[i] != 1) cnt[i]++;
        if(i + l == 1) continue;
        if(prime[cnt[i]] == 0) ans++;
    }
    cout << ans;
}