// 2022-11-20
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

vi A;
vi B;
int n;
vector<vi> dp1(1000, vi(1000, -1));
vector<vi> dp2(1000, vi(1000, -1));
vector<vl> dp3(1000, vl(1000, -1));

int f1(int l, int r){
    if(dp1[l][r] != -1) return dp1[l][r];
    if(l == r) return dp1[l][r] = A[l];
    dp1[l][r] = max(A[l], f1(l + 1, r));
    return dp1[l][r];
}

int f2(int l, int r){
    if(dp2[l][r] != -1) return dp2[l][r];
    if(l == r) return dp2[l][r] = B[l];
    dp2[l][r] = max(B[l], f2(l + 1, r));
    return dp2[l][r];
}

ll f3(int l, int r){
    if(dp3[l][r] != -1) return dp3[l][r];
    if(l == r) return dp3[l][r] = 1LL * A[l] * B[l];
    dp3[l][r] = 1LL * f1(l, r) * f2(l, r);
    for(int i{l}; i < r; ++i){
        dp3[l][r] = min(dp3[l][r], f3(l, i) + f3(i + 1, r));
    }
    return dp3[l][r];
}

int main() {
	fastio;		
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        B.push_back(a);
    }
    cout << f3(0, n - 1);
}
	

