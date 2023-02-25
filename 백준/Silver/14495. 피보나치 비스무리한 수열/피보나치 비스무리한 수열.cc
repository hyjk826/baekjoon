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
    int n;
    cin >> n;
    vl fibo(117);
    fibo[1] = fibo[2] = fibo[3] = 1;
    for(int i{4}; i <= n; ++i){
        fibo[i] = fibo[i - 1] + fibo[i - 3];
    }
    cout << fibo[n];
}
