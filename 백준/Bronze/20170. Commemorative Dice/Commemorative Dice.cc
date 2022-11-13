// 2022-11-13
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	fastio;
    vi A(6), B(6);
    for(int i{0}; i < 6; ++i) cin >> A[i];
    for(int i{0}; i < 6; ++i) cin >> B[i];
    int cnt{0};
    for(int i{0}; i < 6; ++i){
        for(int j{0}; j < 6; ++j){
            if(A[i] > B[j]) cnt++;
        }
    }
    int g = gcd(cnt, 36);
    cout << cnt / g << "/" << 36 / g;
}
	

