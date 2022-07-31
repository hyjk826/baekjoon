// 2022-07-31
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
    vi A(10), B(10);
    for(int i{0}; i < 10; ++i) cin >> A[i];
    for(int i{0}; i < 10; ++i) cin >> B[i];
    int a{0}, b{0};
    for(int i{0}; i < 10; ++i){
        if(A[i] > B[i]) a++;
        else if(A[i] < B[i]) b++;
    }
    if(a > b) cout << "A";
    else if(a < b) cout << "B";
    else cout << "D";
}

