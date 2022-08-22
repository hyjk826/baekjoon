// 2022-08-22
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
    int n, m;
    cin >> n >> m;
    vi ans(n);
    for(int i{0}; i < n; ++i){
        ans[i] = i + 1;
    }
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        swap(ans[a], ans[b]);
    }
    for(auto& i : ans) cout << i << " ";
}

