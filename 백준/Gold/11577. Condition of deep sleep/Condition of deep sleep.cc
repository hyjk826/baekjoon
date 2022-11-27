// 2022-11-26
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

int main() {
	int n, k;
    cin >> n >> k;
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vi pre(n + 2);
    bool ok = true;
    int ans{0};
    for(int i{1}; i <= n; ++i){
        pre[i] += pre[i - 1];
        if(pre[i] & 1) vec[i] ^= 1;
        if(i <= n - k + 1 && vec[i] == 1){
            ans++;
            pre[i]++;
            pre[i + k]--;
            vec[i] = 0;
        }
        else if(i > n - k  + 1 && vec[i] == 1) ok = false;
    }
    if(ok) cout << ans;
    else cout << "Insomnia";
}
	
