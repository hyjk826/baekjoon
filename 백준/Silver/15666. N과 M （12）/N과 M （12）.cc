// 2022-09-13
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

int n, m;
vi vec;
vector<vi> ans;
void dfs(int L, vi& v, int k){
    if(L == m){
        ans.push_back(v);
    }
    else{
        for(int i{k}; i < n; ++i){
            v.push_back(vec[i]);
            dfs(L + 1, v, i);
            v.pop_back();
        }
    }
}

int main() {
	fastio;
    cin >> n >> m;
    vec.resize(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end());
    vi v;
    dfs(0, v, 0);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto& i : ans){
        for(auto& j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
}
	

