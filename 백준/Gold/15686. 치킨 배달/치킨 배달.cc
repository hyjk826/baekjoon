// 2022-09-11
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
vp chicken;
vp house;
vi ch(20);
int ans{MAX};

void dfs(int L, int k){
    if(L == m){
        int cnt{0};
        for(int i{0}; i < (int)house.size(); ++i){
            int mn{MAX};
            for(int j{0}; j < m; ++j){
                mn = min(mn, abs(house[i].first - chicken[ch[j]].first) + abs(house[i].second - chicken[ch[j]].second));
            }
            cnt += mn;
        }
        ans = min(ans, cnt);
    }
    else{
        for(int i{k + 1}; i < (int)chicken.size(); ++i){
            ch[L] = i;
            dfs(L + 1, i);
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            int a;
            cin >> a;
            if(a == 1) house.push_back({i, j});
            else if(a == 2) chicken.push_back({i, j});
        }
    }
    dfs(0, -1);
    cout << ans;
}