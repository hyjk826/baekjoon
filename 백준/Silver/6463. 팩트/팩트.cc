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
    vl vec(10001);
    vec[1] = 1;
    for(int i{2}; i <= 10000; ++i){
        vec[i] = (vec[i - 1] * i);
        while(vec[i] % 10 == 0) vec[i] /= 10;
        vec[i] %= 100000;
    }
    int n;
    while(cin >> n){
        cout << string(5 - to_string(n).size(), ' ');
        cout << n << " -> ";
        int ans = vec[n];
        while(ans % 10 == 0) ans /= 10;
        cout << ans % 10 << "\n";
    }
}

