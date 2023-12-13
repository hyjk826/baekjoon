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

ll ccw(point A, point B, point C){
    ll ret = 1LL * A.x * B.y + 1LL * B.x * C.y + 1LL * C.x * A.y;
    ret -= 1LL * B.x * A.y + 1LL * C.x * B.y + 1LL * A.x * C.y;
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    else return 0;
}

// AB, CD 
ll check(const point& A, const point& B, const point& C, const point& D){
    return (ccw({0, 0}, {B.x - A.x, B.y - A.y}, {D.x - C.x, D.y - C.y}) >= 0);
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
    // if(hull.size() <= 2) hull.clear();
    return hull;
}

ll rotatingCalipers(vector<point>& vec){
    auto hull = convex(vec);
    ll mx{0};
    for(int i{0}, j{0}; i < (int)hull.size(); ++i){
        while(j + 1 < (int)hull.size() && check(hull[i], hull[i + 1], hull[j], hull[j + 1])){
            mx = max(mx, dist(hull[i], hull[j]));
            ++j;
        }
        mx = max(mx, dist(hull[i], hull[j]));
    }
    return mx;
}

ll f(vector<point>& vec, int t, vi& X, vi& Y){
    auto tmp = vec;
    for(int i{0}; i < (int)X.size(); ++i){
        tmp[i].x += 1LL * X[i] * t;
        tmp[i].y += 1LL * Y[i] * t;
    }   
    return rotatingCalipers(tmp);
}




void solve(){
    int n, t;
    cin >> n >> t;
    vector<point> vec(n);
    vi X(n), Y(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y >> X[i] >> Y[i];
    }
    int l{0}, r{t};
    while(r - l >= 3){
        int l2 = (l * 2 + r) / 3;
        int r2 = (l + r * 2) / 3;
        if(f(vec, l2, X, Y) <= f(vec, r2, X, Y)) r = r2;
        else l = l2;
    }
    ll ti{0};
    ll ans{LLONG_MAX};
    for(int i{l}; i <= r; ++i){
        ll k = f(vec, i, X, Y);
        if(k < ans){
            ans = k;
            ti = i;
        }
    }
    cout << ti << "\n" << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
