// 2022-12-15
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
    int n;
    cin >> n;
    string str = "JCBW";
    vector<vp> g(4);
    int sx, sy, tx, ty;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            char c;
            cin >> c;
            if(c == 'X') continue;
            if(c == 'H'){
                sx = i; sy = j;
            }
            else if(c == '#'){
                tx = i; ty = j;
            }
            else{
                int idx = find(str.begin(), str.end(), c) - str.begin();
                if(idx < 4){
                    g[idx].push_back({i, j});
                }
            }
        }
    }
    int mn{MAX};
    int id{-1};
    for(int i{0}; i < 4; ++i){
        sort(g[i].begin(), g[i].end());
        do{
            int x = sx;
            int y = sy;
            int sum{0};
            for(int j{0}; j < 3; ++j){
                sum += abs(x - g[i][j].first);
                sum += abs(y - g[i][j].second);
                x = g[i][j].first;
                y = g[i][j].second;
            }
            sum += abs(x - tx);
            sum += abs(y - ty);
            if(sum < mn){
                id = i;
                mn = sum;
            }
        }while(next_permutation(g[i].begin(), g[i].end()));
    }
    vs name = {"Assassin", "Healer", "Mage", "Tanker"};
    cout << name[id];
}
	
