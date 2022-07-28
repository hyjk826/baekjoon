// 2022-07-28
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
 
int main() {
	fastio;
    string str;
    set<string> s;
    for(int i{0}; i < 9; ++i){
        char c;
        cin >> c;
        str += c;
    }
    s.insert(str);
    queue<pair<string, int> > Q;
    Q.push({str, 0});
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    while(!Q.empty()){
        string t{Q.front().first};
        int cnt{Q.front().second};
        Q.pop();
        if(t == "123456780"){
            cout << cnt;
            return 0;
        }
        int index{-1};
        for(int i{0}; i < 9; ++i){
            if(t[i] == '0') {
                index = i;
                break;
            }
        }
        int x = index / 3;
        int y = index % 3;
        for(int dir{0}; dir < 4; ++dir){
            int nx{x + xx[dir]};
            int ny{y + yy[dir]};
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
            swap(t[x * 3 + y], t[nx * 3 + ny]);
            if(s.count(t) == 0){
                s.insert(t);
                Q.push({t, cnt + 1});
            }
            swap(t[x * 3 + y], t[nx * 3 + ny]);
        }
    }
    cout << -1;
}

