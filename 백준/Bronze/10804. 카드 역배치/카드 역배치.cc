// 2022-07-26
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
    vi ans(20);
    for(int i{0}; i < 20; ++i){
        ans[i] = i + 1;
    }
    for(int i{0}; i < 10; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        reverse(ans.begin() + a, ans.begin() + b);
    }
    for(auto& i : ans) cout << i << " ";
}

