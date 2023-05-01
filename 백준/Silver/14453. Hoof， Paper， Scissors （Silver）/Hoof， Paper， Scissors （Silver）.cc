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
    vi vec(n + 1);
    vi A(n + 1), B(n + 1), C(n + 1);
    for(int i{1}; i <= n; ++i){
        char c;
        cin >> c;
        if(c == 'P') A[i] = 1;
        else if(c == 'H') B[i] = 1;
        else C[i] = 1;
    }
    for(int i{1}; i <= n; ++i){
        A[i] += A[i - 1];
        B[i] += B[i - 1];
        C[i] += C[i - 1];
    }
    int ans = max({A.back(), B.back(), C.back()});
    for(int i{1}; i <= n; ++i){
        ans = max(ans, max({A[i], B[i], C[i]}) + max({A.back() - A[i], B.back() - B[i], C.back() - C[i]}));
    }
    cout << ans;
}
