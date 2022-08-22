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
    int n, m, l;
    cin >> n >> m >> l;
    if(m == 1){
        cout << 0;
        return 0;
    }
    vi ch(n);
    int ans{0};
    int k{0};
    ch[0]++;
    while(1){
        if(ch[k] & 1) k = (k + l) % n;
        else k = (k - l + n) % n;
        ch[k]++;
        ans++;
        if(ch[k] == m) break;
    }
    cout << ans;
}

