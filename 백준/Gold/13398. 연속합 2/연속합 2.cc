// 2022-07-28
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
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    vi post(n + 1), pre(n + 1);
    int ans{-MAX};
    post[n] = vec[n];
    for(int i{n - 1}; i >= 0; --i){
        post[i] = max(vec[i], post[i + 1]);
    }
    for(int i{0}; i < n; ++i){
        ans = max(ans, post[i + 1] - vec[i]);
    }
    for(int i{1}; i <= n; ++i){
        pre[i] = min(vec[i], pre[i - 1]);
    }
    for(int i{2}; i <= n - 1; ++i){
        int sum{0};
        int a = max(0, post[i + 1] - vec[i]);
        int b = max(0, vec[i - 1] - pre[i - 1]);
        if(a == 0 && b == 0) continue;
        ans = max(ans, a + b);
    }
    cout << ans;
}

