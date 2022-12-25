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
};

bool isInside(point A, vector<point>& hull){
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

ll dist(point A, point B){
    ll x = A.x - B.x;
    ll y = A.y - B.y;
    return x * x + y * y;
}

int ccw(point A, point B, point C){
    ll ret = 1LL * A.x * B.y + 1LL * B.x * C.y + 1LL * C.x * A.y;
    ret -= 1LL * B.x * A.y + C.x * B.y + A.x * C.y;
    if(ret > 0) return 1;
    else if(ret < 0) return -1;
    else return 0;
}


int main(){
	fastio;
    int n;
    cin >> n;
    vector<point> vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y;
    }
    for(int i{0}; i < 3; ++i){
        int x, y;
        cin >> x >> y;
        bool ok = false;
        for(int j{0}; j < n; ++j){
            if(ccw(vec[j], vec[(j + 1) % n], {x, y}) == 0 && dist(vec[j], {x, y}) + dist({x, y}, vec[(j + 1) % n]) <= dist(vec[j], vec[(j + 1) % n])){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << 1 << "\n";
            continue;
        }
        if(isInside({x, y}, vec)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}
