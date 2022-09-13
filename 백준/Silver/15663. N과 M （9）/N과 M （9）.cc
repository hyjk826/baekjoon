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
vi vec(8);
vi ch(8);
vector<vi> ans;

void dfs(int L, vi& v){
    if(L == m){
        ans.push_back(v);
    }
    else{
        for(int i{0}; i < n; ++i){
            if(ch[i] == 0){
                ch[i] = 1;
                v.push_back(vec[i]);
                dfs(L + 1, v);
                v.pop_back();
                ch[i] = 0;
            }
        }
    }
}
int main() {
	fastio;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi v;
    dfs(0, v);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto& i : ans){
        for(auto& j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
}
	

