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
    int n;
    cin >> n;
    vi vec(1002);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        vec[a] = b;
    }
    vi pre = vec;
    vi post = vec;
    for(int i{1}; i <= 1000; ++i){
        pre[i] = max(vec[i], pre[i - 1]);
    }
    for(int i{1000}; i >= 0; --i){
        post[i] = max(vec[i], post[i + 1]);
    }
    int ans{0};
    for(int i{1}; i <= 1000; ++i){
        ans += min(pre[i], post[i]);
    }
    cout << ans;
}

