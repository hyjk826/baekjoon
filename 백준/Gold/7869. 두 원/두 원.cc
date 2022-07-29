// 2022-07-29
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double PI = acos(-1);
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double ans;
    if(r1 + r2 <= d) ans = 0;
    else if(abs(r1 - r2) >= d){
        ans = min(r1, r2) * min(r1, r2) * PI;
    }
    else{
        double a1 = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
        double a2 = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
        double s1 = (r1 * r1 * a1) - (r1 * r1 * sin(2 * a1) / 2);
        double s2 = (r2 * r2 * a2) - (r2 * r2 * sin(2 * a2) / 2);
        ans = s1 + s2;
    }
    printf("%.3f", ans);
}

