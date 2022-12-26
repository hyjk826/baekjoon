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
    int x, y, idx;
    bool operator< (const point& a) const{
        if(y == a.y) return x < a.x;
        return y < a.y;
    }
    bool operator== (const point& a) const{
        return (x == a.x && y == a.y);
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

int main() {
	fastio;	
    int n;
    cin >> n;
    vector<point> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y;
        vec[i].idx = i;
    }
    vi ans(n);
    int cnt{1};
    while(vec.size() >= 3){
        auto hull = convex(vec);
        if(hull.empty()) break;
        for(auto& i : hull){
            ans[i.idx] = cnt;
            auto it = find(vec.begin(), vec.end(), point({i.x, i.y}));
            vec.erase(it);
        }
        cnt++;
    }
    for(auto& i : ans) cout << i << " ";
}
	
