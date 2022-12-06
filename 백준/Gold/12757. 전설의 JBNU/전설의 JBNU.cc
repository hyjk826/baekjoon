// 2022-12-04
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

map<int, int> mp;
int n, m, k;

int getKey(int a){
    if(mp.count(a)) return a;
    auto r = mp.upper_bound(a);
    auto l = mp.lower_bound(a);
    int x = -1;
    int y = -1;
    if(r != mp.end() && abs(a - r->first) <= k) x = r->first;
    if(l != mp.begin() && abs(a - prev(l)->first) <= k) y = prev(l)->first;
    if(x == -1 && y == -1) return -1;
    if(x == -1) return y;
    if(y == -1) return x;
    if(abs(a - x) == abs(a - y)) return -2;
    else if(abs(a - x) < abs(a - y)) return x;
    else return y;
}


int main() {
	fastio;
    cin >> n >> m >> k;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b >> c;
            mp[b] = c;
        }
        else if(a == 2){
            cin >> b >> c;
            int key = getKey(b);
            if(key >= 0) mp[key] = c;
        }
        else{
            cin >> b;
            int key = getKey(b);
            if(key >= 0) cout << mp[key] << "\n";
            else if(key == -1) cout << -1 << "\n";
            else if(key == -2) cout << "?\n";
        }
    }
}
	
