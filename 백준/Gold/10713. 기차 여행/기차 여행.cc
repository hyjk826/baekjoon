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
    vi path(m);
    for(int i{0}; i < m; ++i){
        cin >> path[i];
    }
    vi ch(n + 1);
    for(int i{0}; i < m - 1; ++i){
        int a = min(path[i], path[i + 1]);
        int b = max(path[i], path[i + 1]);
        ch[a]++;
        ch[b]--;
    }
    for(int i{1}; i <= n; ++i){
        ch[i] += ch[i - 1];
    }
    vi A(n), B(n), C(n);
    for(int i{1}; i < n; ++i){
        cin >> A[i] >> B[i] >> C[i];
    }
    int ans{0};
    for(int i{1}; i < n; ++i){
        ans += min(ch[i] * A[i], C[i] + ch[i] * B[i]);
    }
    cout << ans;
}
