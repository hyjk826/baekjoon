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

int p[501];

int find(int a){
    if(a == p[a]) return a;
    return p[a] = find(p[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

struct st{
    int a, b;
    ll w;
};

struct point{
    ll x, y;
};

ll dist(point& A, point& B){
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

bool onTheLine(point A, point B, point C){
    if(ccw(A, B, C) == 0 && dist(A, B) + dist(B, C) <= dist(A, C)) return 1;
    else return 0;
}

void solve(){
	int n, m;
    cin >> n >> m;
    vector<point> vec(n + 1);
    for(int i{1}; i <= n; ++i){
        p[i] = i;
        cin >> vec[i].x >> vec[i].y;
    }
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    ll ans{0};
    vector<st> edge;
    for(int i{1}; i <= n; ++i){
        for(int j{i + 1}; j <= n; ++j){
            edge.push_back({i, j, dist(vec[i], vec[j])});
        }
    }
    sort(edge.begin(), edge.end(), [&](st& x, st& y){
        return x.w > y.w;
    });
    for(auto& i : edge){
        bool ok = true;
        for(int j{1}; j <= n; ++j){
            if(j == i.a || j == i.b) continue;
            if(onTheLine(vec[i.a], vec[j], vec[i.b])) {
                ok = false; break;
            }
        }
        if(!ok) continue;
        if(merge(i.a, i.b)) {
            ans += i.w;
        }
    }
    cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
