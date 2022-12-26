// 2022-12-26
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

struct point{
    int x, y;
    bool operator< (const point& a) const{
        if(y == a.y) return x < a.x;
        return y < a.y;
    }
};

int ccw(point A, point B, point C){
    ll ret = 1LL * A.x * B.y + 1LL * B.x * C.y + 1LL * C.x * A.y;
    ret -= 1LL * B.x * A.y + 1LL * C.x * B.y + 1LL * A.x * C.y;
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    else return 0;
}

int ccw2(pl a, pl b, pl c){
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
    int ab = ccw2(a, b, c) * ccw2(a, b, d);
    int cd = ccw2(c, d, a) * ccw2(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

ll dist(point& A, point& B){
    ll x = A.x - B.x;
    ll y = A.y - B.y;
    return x * x + y * y;
}

vector<point> convex(vector<point>& vec){
    swap(vec[0], *min_element(vec.begin(), vec.end()));
    sort(vec.begin() + 1, vec.end(), [&](point& A, point& B){
        int k = ccw(vec[0], A, B);
        if(k == 0) return dist(vec[0], A) < dist(vec[0], B);
        else return k > 0;
    });
    vector<point> hull;
    for(auto& i : vec){
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), i) <= 0){
            hull.pop_back();
        }
        hull.push_back(i);
    }
    return hull;
}

bool isInside(point& A, vector<point>& hull){
    int cnt{0};
    for(int i{0}; i < (int)hull.size(); ++i){
        int j = (i + 1) % (int)hull.size();
        if((hull[i].y > A.y) != (hull[j].y > A.y)){
            double interX = 1.0 * (hull[j].x - hull[i].x) * (A.y - hull[i].y) / (hull[j].y - hull[i].y) + hull[i].x;
            if(A.x < interX) cnt++;
        }
    }
    return (cnt & 1);
}

int main() {
	fastio;	
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<point> A(n), B(m);
        for(int i{0}; i < n; ++i){
            cin >> A[i].x >> A[i].y;
        }
        for(int i{0}; i < m; ++i){
            cin >> B[i].x >> B[i].y;
        }
        auto hull1 = convex(A);
        auto hull2 = convex(B);
        bool ok = false;
        for(int i{0}; i < (int)hull1.size(); ++i){
            ok |= isInside(hull1[i], hull2);
        }
        for(int i{0}; i < (int)hull2.size(); ++i){
            ok |= isInside(hull2[i], hull1);
        }
        for(int i{0}; i < (int)hull1.size(); ++i){
            for(int j{0}; j < (int)hull2.size(); ++j){
                auto a = hull1[i];
                auto b = hull1[(i + 1) % hull1.size()];
                auto c = hull2[j];
                auto d = hull2[(j + 1) % hull2.size()];
                ok |= isIntersect({{a.x, a.y}, {b.x, b.y}}, {{c.x, c.y}, {d.x, d.y}});
            }
        }
        if(ok) cout << "NO\n";
        else cout << "YES\n";
    }
}
	
