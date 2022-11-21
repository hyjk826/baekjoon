// 2022-11-21
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
	int sx, sy, tx, ty;
    sx = tx = -1;
    int n, m;
    cin >> n >> m;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            int a;
            cin >> a;
            if(a == 0) continue;
            if(sx == -1){
                sx = i;
                sy = j;
            }
            else{
                tx = i;
                ty = j;
            }
        }
    }
    cout << abs(sx - tx) + abs(sy - ty);
}
	

