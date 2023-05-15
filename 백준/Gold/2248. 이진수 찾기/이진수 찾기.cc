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

ll com[40][40];

ll C(int a, int b){
    if(com[a][b] != -1) return com[a][b];
    if(a == b || b == 0) return com[a][b] = 1;
    return com[a][b] = C(a - 1, b - 1) + C(a - 1, b);
}


int main(){
	fastio;
    memset(com, -1LL, sizeof(com));
    ll N, L, I;
    cin >> N >> L >> I;
    function<void(ll,ll,ll)> f = [&](ll n, ll l, ll k){
        if(n == N) return;
        if(l == 0){
            cout << 0;
            f(n + 1, l, k);
        }
        else{
            ll sum{0};
            for(int i{0}; i <= min(N - n - 1, (ll)l); ++i){
                sum += C(N - n - 1, i);
            }
            if(k <= sum){
                cout << 0;
                f(n + 1, l, k);
            }
            else{
                cout << 1;
                f(n + 1, l - 1, k - sum);
            }
        }
    };
    f(0, L, I);
}
