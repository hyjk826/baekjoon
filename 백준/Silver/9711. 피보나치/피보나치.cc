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
    vl fibo(10001);
    int t;
    cin >> t;
    for(int T{1}; T <= t; ++T){
        cout << "Case #" << T << ": ";
        int p, q;
        cin >> p >> q;
        fibo[1] = fibo[2] = 1;
        for(int i{3}; i <= p; ++i){
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % q;
        }
        cout << fibo[p] % q << "\n";
    }
}
