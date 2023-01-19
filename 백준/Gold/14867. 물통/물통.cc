// 2023-01-19
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    queue<pi> Q;
    map<pi, int> mp;
    mp[{0,0}] = 0;
    Q.push({0, 0});
    while(!Q.empty()){
        int x{Q.front().first};
        int y{Q.front().second};
        Q.pop();
        for(int i{0}; i < 6; ++i){
            int nx, ny;
            if(i == 0){
                nx = a;
                ny = y;
            }
            else if(i == 1){
                nx = x;
                ny = b;
            }
            else if(i == 2){
                nx = 0;
                ny = y;
            }
            else if(i == 3){
                nx = x;
                ny = 0;
            }
            else if(i == 4){
                int k = min(x, b - y);
                nx = x - k;
                ny = y + k;
            }
            else {
                int k = min(y, a - x);
                nx = x + k;
                ny = y - k;
            }
            if(mp.count({nx, ny})) continue;
            mp[{nx, ny}] = mp[{x, y}] + 1;
            Q.push({nx, ny});
        }
    }
    if(mp.count({c, d})) cout << mp[{c, d}];
    else cout << -1;
}
