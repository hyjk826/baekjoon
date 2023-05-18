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
    int l, r, w;
};


int main(){
	fastio;
    int n, c;
    cin >> n >> c;
    int m;
    cin >> m;
    vector<st> vec(m);
    for(int i{0}; i < m; ++i){
        cin >> vec[i].l >> vec[i].r >> vec[i].w;
    }
    sort(vec.begin(), vec.end(), [&](st& a, st& b){
        if(a.r == b.r) return a.l < b.l;
        return a.r < b.r;
    });
    vi A(n);
    int ans{0};
    for(int i{0}; i < m; ++i){
        int l = vec[i].l; 
        int r = vec[i].r;
        int w = vec[i].w;
        int mx = *max_element(A.begin() + l, A.begin() + r);
        int k = min(vec[i].w, c - mx);
        for(int j{l}; j < r; ++j){
            A[j] += k;
        }
        ans += k;
    }
    cout << ans;
}