// 2022-09-14
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

int ccw(pl a, pl b, pl c){
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pl, pl> x, pair<pl, pl> y){
    pl a = x.first;
    pl b = x.second;
    pl c = y.first;
    pl d = y.second;
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
	fastio;
    pair<pl, pl> x, y;
    cin >> x.first.first >> x.first.second >> x.second.first >> x.second.second;
    cin >> y.first.first >> y.first.second >> y.second.first >> y.second.second;
    if(isIntersect(x, y)) cout << 1;
    else cout << 0;
}
	

