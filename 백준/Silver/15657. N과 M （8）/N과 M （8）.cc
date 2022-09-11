// 2022-09-12
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m;
vi vec;

void dfs(int L, int k, vi& r){
    if(L == m){
        for(auto& i : r) cout << i << " ";
        cout << "\n";
    }
    else{
        for(int i{k}; i < n; ++i){
            r.push_back(vec[i]);
            dfs(L + 1, i, r);
            r.pop_back();
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    vec.resize(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vi r;
    dfs(0, 0, r);
}