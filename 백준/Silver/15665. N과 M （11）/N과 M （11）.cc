// 2022-07-23
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, k;
vi vec;
vector<vi> ans;

void dfs(int L, vi& v){
    if(L == k){
        ans.push_back(v);
    }
    else{
        for(auto& i : vec){
            v.push_back(i);
            dfs(L + 1, v);
            v.pop_back();
        }
    }
}

int main() {
	fastio;
    cin >> n >> k;
    vec.resize(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    vi v;
    dfs(0, v);
    for(auto& i : ans){
        for(auto& j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
}

