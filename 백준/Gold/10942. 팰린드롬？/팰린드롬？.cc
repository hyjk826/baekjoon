// 2022-09-14
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

int n;
vi vec(2000);
vector<vi> p(2000, vi(2000, -1));
bool f(int l, int r){
    if(p[l][r] != -1) return p[l][r];
    if(l > r || l == r) return true;
    if(vec[l] == vec[r]) return p[l][r] = f(l + 1, r - 1);
    else return p[l][r] = 0;
}


int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(f(l, r)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
	

