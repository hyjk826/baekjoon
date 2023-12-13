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

void solve(){
    int n, m;
    cin >> n >> m;
    vp A(n), B(m);
    vector<point> vec;
    for(int i{0}; i < n; ++i) cin >> A[i].first >> A[i].second;
    for(int i{0}; i < m; ++i) cin >> B[i].first >> B[i].second;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            vec.push_back({A[i].second + B[j].second, A[i].first + B[j].first});
        }
    }
    auto hull = convex(vec);
    cout << hull.size() << "\n";
    cout << hull[0].y << " " << hull[0].x << "\n";
    for(int i{(int)hull.size() - 1}; i >= 1; --i) cout << hull[i].y << " " << hull[i].x << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
