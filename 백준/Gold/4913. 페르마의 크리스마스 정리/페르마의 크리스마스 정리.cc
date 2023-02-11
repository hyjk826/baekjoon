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

int main(){
	fastio;
    vi prime((int)1e6 + 1);
    for(ll i{2}; i <= 1e6; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= 1e6; j += i){
            prime[j] = 1;
        }
    }
    vi A, B;
    for(int i{2}; i <= (int)1e6; ++i){
        if(prime[i]) continue;
        A.push_back(i);
        if(i == 2 || i % 4 == 1) B.push_back(i);
    }
    int a, b;
    while(cin >> a >> b){
        if(a == -1 && b == -1) break;
        int l = max(a, 2);
        int r = b;
        int x{0}, y{0};
        if(l <= r){
            x = upper_bound(A.begin(), A.end(), r) - lower_bound(A.begin(), A.end(), l);
            y = upper_bound(B.begin(), B.end(), r) - lower_bound(B.begin(), B.end(), l);
        }
        cout << a << " " << b << " " << x << " " << y << "\n";
    }
}
