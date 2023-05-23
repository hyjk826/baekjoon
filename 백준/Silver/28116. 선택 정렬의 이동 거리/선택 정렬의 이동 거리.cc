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
    vi idx(n + 1);
    for(int i{1}; i <= n; ++i) {
        cin >> vec[i];
        idx[vec[i]] = i;
    }
    vi ans(n + 1);
    for(int i{1}; i <= n; ++i){
        int k = abs(i - idx[i]);
        int a = idx[i];
        ans[vec[i]] += k;
        ans[vec[a]] += k;
        idx[vec[i]] = a;
        idx[vec[a]] = i;
        swap(vec[i], vec[a]);
    }
    for(int i{1}; i <= n; ++i) cout << ans[i] << " ";
}
