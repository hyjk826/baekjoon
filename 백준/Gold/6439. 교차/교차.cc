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
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        int ax, ay, bx, by;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> ax >> ay >> bx >> by;
        if(ax > bx) swap(ax, bx);
        if(ay < by) swap(ay, by);
        if(ax <= x1 && x1 <= bx && ax <= x2 && x2 <= bx && ay >= y1 && y1 >= by && ay >= y2 && y2 >= by){
            cout << "T\n"; continue;
        }
        bool ok = false;
        ok |= isIntersect({{x1, y1}, {x2, y2}}, {{ax,ay}, {bx, ay}});
        ok |= isIntersect({{x1, y1}, {x2, y2}}, {{ax,ay}, {ax, by}});
        ok |= isIntersect({{x1, y1}, {x2, y2}}, {{bx,by}, {bx, ay}});
        ok |= isIntersect({{x1, y1}, {x2, y2}}, {{bx,by}, {ax, by}});
        if(ok) cout << "T\n";
        else cout << "F\n";
    }
}
