// 2022-07-25
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

int n, m, h;
int ans{MAX};
int ch[33][13]{};
vp vec;


void dfs(int L, int k){
    if(L == 0){
        bool f = 1;
        for(int i{1}; i <= n; ++i){
            int k = i;
            for(int j{1}; j <= h; ++j){
                if(ch[j][k]) k++;
                else if(ch[j][k - 1]) k--;
            }
            if(k != i){
                f = 0;
                break;
            }
        }
        if(f) ans = L;
    }
    else{
        for(int i{k + 1}; i < (int)vec.size(); ++i){
            int a = vec[i].first;
            int b = vec[i].second;
            if(ch[a][b] || ch[a][b + 1] || ch[a][b - 1]) continue;
            ch[a][b] = 1;
            dfs(L - 1, i);
            ch[a][b] = 0;
        }
    }
}

int main() {
	fastio;
    cin >> n >> m >> h;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        ch[a][b] = 1;
    }
    for(int i{1}; i <= h; ++i){
        for(int j{1}; j <= n; ++j){
            if(ch[i][j] || ch[i][j - 1] || ch[i][j + 1]) continue;
            vec.push_back({i, j});
        }
    }
    for(int i{0}; i <= 3; ++i){
        dfs(i, -1);
        if(ans != MAX){
            cout << i;
            return 0;
        }
    }
    cout << -1;
}

