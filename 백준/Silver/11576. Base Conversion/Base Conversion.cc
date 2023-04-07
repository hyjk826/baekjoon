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
    int a, b;
    cin >> a >> b;
    int k{1};
    int x{0};
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{n - 1}; i >= 0; --i){
        x += k * vec[i];
        k *= a;
    }
    vi ans;
    while(x){
        ans.push_back(x % b);
        x /= b;
    }
    reverse(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << " ";
}
