// 2022-08-23
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
    vi A(9), B(9);
    for(int i{0}; i < 9; ++i) cin >> A[i];
    for(int i{0}; i < 9; ++i) cin >> B[i];
    int a, b;
    a = b = 0;
    for(int i{0}; i < 9; ++i){
        a += A[i];
        if(a > b){
            cout << "Yes";
            return 0;
        }
        b += B[i];
    }
    cout << "No";
}

