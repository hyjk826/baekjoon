// 2022-12-18
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

void intersection(pl a, pl b, pl c, pl d){
    cout << fixed << setprecision(20);
    if(isIntersect({a, b}, {c, d})){
        cout << 1 << "\n";
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        if(b == c) cout << b.first << " " << b.second << "\n";
        else if(a == d) cout << a.first << " " << a.second << "\n";
        else{
            ll x = (a.first * b.second - a.second * b.first) * (c.first - d.first) - (c.first * d.second - c.second * d.first) * (a.first - b.first);
            ll y = (a.first * b.second - a.second * b.first) * (c.second - d.second) - (c.first * d.second - c.second * d.first) * (a.second - b.second);
            ll div = (a.first - b.first) * (c.second - d.second) - (a.second - b.second) * (c.first - d.first);
            if(div == 0) return;
            cout << 1.0 * x / div << " " << 1.0 * y / div << "\n";
        }
    }
    else{
        cout << 0 << "\n";
    }
}

int main(){
	fastio;
    pl A, B, C, D;
    cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> D.first >> D.second;
    intersection(A, B, C, D);
}
	
