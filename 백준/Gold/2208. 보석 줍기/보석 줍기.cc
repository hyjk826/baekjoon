// 2023-01-03
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
    int n, m;
    cin >> n >> m;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    vi post(n + 1);
    post.back() = vec.back();
    for(int i{n - 1}; i >= 0; --i){
        post[i] = max(post[i + 1], vec[i]);
    }
    int ans{0};
    for(int i{0}; i + m <= n; ++i){
        ans = max(ans, post[i + m] - vec[i]);
    }
    cout << ans;
}
