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

struct st{
    int l, r, k;
};

int main(){
	fastio;
    int n;
    cin >> n;
    vi A;
    vector<st> vec(n);
    for(int i{0}; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        vec[i] = {a, b, c};
        A.push_back(a);
        A.push_back(b);
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.l < y.l; 
    });
    for(int i{0}; i < n; ++i){
        vec[i].l = lower_bound(A.begin(), A.end(), vec[i].l) - A.begin() + 1;
        vec[i].r = lower_bound(A.begin(), A.end(), vec[i].r) - A.begin() + 1;
    }
    vi dp((int)A.size() + 1);
    for(auto& i : vec){
        int mx{0};
        for(int j{i.l}; j >= 0; --j){
            mx = max(mx, dp[j]);
        }
        dp[i.r] = max(dp[i.r], mx + i.k);
    }
    cout << *max_element(dp.begin(), dp.end());
}
