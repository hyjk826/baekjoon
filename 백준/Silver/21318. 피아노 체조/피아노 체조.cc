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
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
    }
    vi ch(n + 1);
    for(int i{1}; i < n; ++i){
        if(vec[i] > vec[i + 1]) ch[i] = 1;
        ch[i] += ch[i - 1];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l == r) cout << 0 << "\n";
        else cout << ch[r - 1] - ch[l - 1] << "\n";
    }
}
