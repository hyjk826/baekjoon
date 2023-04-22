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
    ll x, y;
     bool operator< (const point& a) const{
        if(y == a.y) return x < a.x;
        return y < a.y;
    } 
};

int dot(point A, point B){
    return A.x * B.x + A.y * B.y;
}

double dd(point& A, point& B, point& C){
    double d1 = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    double d2 = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    d2 = sqrt(d2);
    return d1 / d2;
}

int ccw(point A, point B, point C){
    ll ret = 1LL * A.x * B.y + 1LL * B.x * C.y + 1LL * C.x * A.y;
    ret -= 1LL * B.x * A.y + 1LL * C.x * B.y + 1LL * A.x * C.y;
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    else return 0;
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
    if(hull.size() <= 2) hull.clear();
    return hull;
}


int main(){
	fastio;
    cout << fixed << setprecision(2);
    for(int T{1};; ++T){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<point> vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i].x >> vec[i].y;
        }
        auto hull = convex(vec);
        double ans{1e10};
        for(int i{0}; i < (int)hull.size(); ++i){
            double mx{0};
            for(int j{0}; j < (int)hull.size(); ++j){
                mx = max(mx, dd(hull[i], hull[(i + 1) % (int)hull.size()], hull[j]));
            }
            ans = min(ans, mx);
        }
        cout << "Case " << T << ": " << ceil(ans * 100) / 100 << "\n";
    }
}
