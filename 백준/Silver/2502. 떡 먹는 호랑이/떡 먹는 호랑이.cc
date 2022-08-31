// 2022-08-31
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
    ll d, k;
    cin >> d >> k;
    vl A(d + 1), B(d + 1);
    A[0] = B[1] = 1;
    A[1] = B[0] = 0;
    for(int i{2}; i <= d - 1; ++i){
        A[i] = A[i - 1] + A[i - 2];
        B[i] = B[i - 1] + B[i - 2];
    }
    for(int i{1};;++i){
        ll x = i * A[d - 1];
        if((k - x) % B[d - 1] == 0){
            cout << i << "\n" << (k - x) / B[d - 1];
            return 0;
        }
    }   
}


