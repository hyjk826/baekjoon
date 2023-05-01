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
    int n, q;
    cin >> n >> q;
    vi vec(n + 1);
    vi A(n + 1), B(n + 1), C(n + 1);
    for(int i{1}; i <= n; ++i){
        int a;
        cin >> a;
        if(a == 1) A[i] = 1;
        else if(a == 2) B[i] = 1;
        else C[i] = 1;
    }
    for(int i{1}; i <= n; ++i){
        A[i] += A[i - 1];
        B[i] += B[i - 1];
        C[i] += C[i - 1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << A[r] - A[l - 1] << " " << B[r] - B[l - 1] << " " << C[r] - C[l - 1] << "\n";
    }
}
