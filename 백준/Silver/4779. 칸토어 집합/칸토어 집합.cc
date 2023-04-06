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
    while(cin >> n){
        int k{1};
        for(int i{0}; i < n; ++i) k *= 3;
        vc ans(k, '-');
        function<void(int,int)> f = [&](int l, int r){
            if(l == r) return;
            int len = r - l + 1;
            int a = len / 3;
            for(int i{l + a}; i < l + 2 * a; ++i){
                ans[i] = ' ';
            }
            f(l, l + a - 1);
            f(l + 2 * a, r);
        };
        f(0, k - 1);
        for(auto& i : ans) cout << i;
        cout << "\n";
    }
}
