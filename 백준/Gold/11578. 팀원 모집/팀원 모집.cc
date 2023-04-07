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
    int n, m;
    cin >> n >> m;
    vector<vi> vec(m);
    for(int i{0}; i < m; ++i){
        int k;
        cin >> k;
        vec[i].resize(k);
        for(int j{0}; j < k; ++j){
            cin >> vec[i][j];
        }
    }
    int ans{MAX};
    for(int i{1}; i < (1 << m); ++i){
        unordered_set<int> st;
        for(int j{0}; j < m; ++j){
            if((i >> j) & 1){
                for(auto& k : vec[j]){
                    st.insert(k);
                }
            }
        }
        if(st.size() == n){
            ans = min(ans, __builtin_popcount(i));
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}
