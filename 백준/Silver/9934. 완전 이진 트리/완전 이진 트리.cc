// 2022-09-03
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

int k, n;
vi vec(1024);
vector<vi> ans(10);

void f(int L, int l, int r){
    if(l > r) return;
    int m = (l + r) / 2;
    ans[L].push_back(vec[m]);
    f(L + 1, l, m - 1);
    f(L + 1, m + 1, r);
}

int main() {
	fastio;
    cin >> k;
    n = (1 << k) - 1;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    f(0, 0, n - 1);
    for(int i{0}; i < k; ++i){
        for(auto& j : ans[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}
	

