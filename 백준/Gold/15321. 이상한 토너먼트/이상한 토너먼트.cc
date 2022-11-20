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

vector<vi> dp1(500, vi(500, -1));
vector<vi> dp2(500, vi(500, -1));
vi vec(500);
int n;

int f1(int l, int r){
    if(dp1[l][r] != -1) return dp1[l][r];
    if(l == r) return dp1[l][r] = vec[l];
    return dp1[l][r] = max(vec[l], f1(l + 1, r));
}

int f2(int l, int r){
    if(dp2[l][r] != -1) return dp2[l][r];
    if(l == r) return dp2[l][r] = 0;
    dp2[l][r] = MAX;
    for(int i{l}; i <= r - 1; ++i){
        dp2[l][r] = min(dp2[l][r], f2(l, i) + f2(i + 1, r) + abs(f1(l, i) - f1(i + 1, r)));
    }   
    return dp2[l][r];
}




int main() {
	fastio;	
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    cout << f2(0, n - 1);
}
	

