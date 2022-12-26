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
    ret -= 1LL * B.x * A.y + C.x * B.y + A.x * C.y;
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    else return 0;
}

double dist(point& A, point& B){
    ll x = A.x - B.x;
    ll y = A.y - B.y;
    return sqrt(x * x + y * y);
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

int dot(point A, point B){
    return A.x * B.x + A.y * B.y;
}


double ang(point& A, point& B, point& C){
    double ret = dot({A.x - B.x, A.y - B.y}, {C.x - B.x, C.y - B.y});
    ret /= dist(A, B);
    ret /= dist(B, C);
    return acos(ret);
}

int main() {
	fastio;	
    int n, L;
    cin >> n >> L;
    vector<point> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y;
    }
    auto hull = convex(vec);
    double ans{0};
    int sz = (int)hull.size();
    double PI = acos(-1);
    for(int i{0}; i < sz; ++i){
        ans += dist(hull[i], hull[(i + 1) % sz]);
        ans += L * (PI - ang(hull[(i + sz - 1) % sz], hull[i], hull[(i + 1) % sz]));
    }
    cout << fixed << setprecision(20);
    cout << ans;
}
	
