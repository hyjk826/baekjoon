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
};

point p2v(point a, point b) 
{
    return { b.x - a.x, b.y - a.y };
}

int ccw(point v1, point v2) {
    ll res = v1.x * v2.y - v1.y * v2.x;
    if (res > 0) return 1;
    else if (res < 0) return -1;
    else return 0;
}

bool isInside(vector<point>& CH, point A){
    int n = CH.size();
    point vec_l = p2v(CH[0], CH[n - 1]);
    point vec_r = p2v(CH[0], CH[1]);
    point vec_c = p2v(CH[0], A);
    if (ccw(vec_l, vec_c) > 0) return false;
    if (ccw(vec_r, vec_c) < 0) return false;
    int l = 1, r = n - 1;
    while (l + 1 < r){
        int m = (l + r) / 2; 
        point vec_m = p2v(CH[0], CH[m]);
        if (ccw(vec_m, vec_c) > 0) l = m;
        else r = m;
    }
    point v1 = p2v(CH[l], A);
    point v2 = p2v(A, CH[l + 1]);
    return ccw(v1, v2) < 0;
}

int main(){
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<point> A(n), B(m), C(k);
    for(int i{0}; i < n; ++i){
        cin >> A[i].x >> A[i].y;
    }
    for(int i{0}; i < m; ++i){
        cin >> B[i].x >> B[i].y;
    }
    for(int i{0}; i < k; ++i){
        cin >> C[i].x >> C[i].y;
    }
    int cnt{0};
    for(int i{0}; i < k; ++i){
        bool ok = true;
        ok &= (isInside(A, C[i]));
        ok &= (!isInside(B, C[i]));
        if(!ok) cnt++;
    }
    if(cnt == 0) cout << "YES";
    else cout << cnt;
}
