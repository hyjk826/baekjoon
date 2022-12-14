// 2022-12-14
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

int main() {
	fastio;
    int n, m, h;
    cin >> n >> m >> h;
    vp milk;
    int sx, sy;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            char c;
            cin >> c;
            if(c == '1'){
                sx = i; sy = j;
            }
            else if(c == '2'){
                milk.push_back({i, j});
            }
        }
    }
    sort(milk.begin(), milk.end());
    int ans{0};
    do{
        int x = sx; 
        int y = sy;
        int H = m;
        bool ok = true;
        for(int i{0}; i < (int)milk.size(); ++i){
            H -= abs(milk[i].first - x);
            H -= abs(milk[i].second - y);
            if(H < 0) break;
            H += h;
            x = milk[i].first;
            y = milk[i].second;
            if(abs(sx - x) + abs(sy - y) <= H){
                ans = max(ans, i + 1);
            }
        }
    }while(next_permutation(milk.begin(), milk.end()));
    cout << ans;
}
	
