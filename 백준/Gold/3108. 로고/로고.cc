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

int p[1000];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b; return true;
    }
    return false;
}

struct st{
    int x1, y1, x2, y2;
};

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

bool intersect(st& a, st& b){
    bool ret{0};
    ret |= isIntersect({{a.x1, a.y1}, {a.x2, a.y1}}, {{b.x1, b.y1}, {b.x2, b.y1}});
    ret |= isIntersect({{a.x1, a.y1}, {a.x2, a.y1}}, {{b.x2, b.y1}, {b.x2, b.y2}});
    ret |= isIntersect({{a.x1, a.y1}, {a.x2, a.y1}}, {{b.x2, b.y2}, {b.x1, b.y2}});
    ret |= isIntersect({{a.x1, a.y1}, {a.x2, a.y1}}, {{b.x1, b.y2}, {b.x1, b.y1}});
    
    ret |= isIntersect({{a.x2, a.y1}, {a.x2, a.y2}}, {{b.x1, b.y1}, {b.x2, b.y1}});
    ret |= isIntersect({{a.x2, a.y1}, {a.x2, a.y2}}, {{b.x2, b.y1}, {b.x2, b.y2}});
    ret |= isIntersect({{a.x2, a.y1}, {a.x2, a.y2}}, {{b.x2, b.y2}, {b.x1, b.y2}});
    ret |= isIntersect({{a.x2, a.y1}, {a.x2, a.y2}}, {{b.x1, b.y2}, {b.x1, b.y1}});

    ret |= isIntersect({{a.x2, a.y2}, {a.x1, a.y2}}, {{b.x1, b.y1}, {b.x2, b.y1}});
    ret |= isIntersect({{a.x2, a.y2}, {a.x1, a.y2}}, {{b.x2, b.y1}, {b.x2, b.y2}});
    ret |= isIntersect({{a.x2, a.y2}, {a.x1, a.y2}}, {{b.x2, b.y2}, {b.x1, b.y2}});
    ret |= isIntersect({{a.x2, a.y2}, {a.x1, a.y2}}, {{b.x1, b.y2}, {b.x1, b.y1}});

    ret |= isIntersect({{a.x1, a.y2}, {a.x1, a.y1}}, {{b.x1, b.y1}, {b.x2, b.y1}});
    ret |= isIntersect({{a.x1, a.y2}, {a.x1, a.y1}}, {{b.x2, b.y1}, {b.x2, b.y2}});
    ret |= isIntersect({{a.x1, a.y2}, {a.x1, a.y1}}, {{b.x2, b.y2}, {b.x1, b.y2}});
    ret |= isIntersect({{a.x1, a.y2}, {a.x1, a.y1}}, {{b.x1, b.y2}, {b.x1, b.y1}});

    return ret;
}



int main(){
	fastio;
	int n;
    cin >> n;
    int ans{n};
    vector<st> vec(n + 1);
    bool ok = false;
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].x1 >> vec[i].y1 >> vec[i].x2 >> vec[i].y2;
    }
    iota(p, p + n + 1, 0);
    for(int i{0}; i <= n; ++i){
        for(int j{i + 1}; j <= n; ++j){
            if(intersect(vec[i], vec[j])) {
                if(merge(i, j)){
                    ans--;
                }            
            }
        }
    }
    cout << ans;
}
