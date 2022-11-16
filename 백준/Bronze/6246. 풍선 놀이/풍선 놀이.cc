// 2022-11-16
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
	fastio;
    int n, q;
    cin >> n >> q;
    vi ch(n + 1);
    while(q--){
        int a, b;
        cin >> a >> b;
        for(int i{a}; i <= n; i += b){
            ch[i] = 1;
        }        
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0) ans++;
    }
    cout << ans;
}
	

