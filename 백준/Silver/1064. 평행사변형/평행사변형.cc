// 2022-08-23
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

double dis(pi a, pi b){
    int x = a.first - b.first;
    int y = a.second - b.second;
    return sqrt(x * x + y * y);
}

int main() {
	fastio;
    vector<pi> vec(3);
    for(int i{0}; i < 3; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    cout << fixed << setprecision(10);
    if((vec[0].first - vec[1].first) * (vec[1].second - vec[2].second) == (vec[1].first - vec[2].first) * (vec[0].second - vec[1].second)){
        cout << -1.0;
        return 0;
    }
    double mx{0}, mn{MAX};
    for(int i{0}; i < 3; ++i){
        for(int j{i + 1}; j < 3; ++j){
            double k = dis(vec[i], vec[j]);
            int c = 3 - i - j;
            k += max(dis(vec[i], vec[c]), dis(vec[j], vec[c]));
            mx = max(mx, 2 * (k + max(dis(vec[i], vec[c]), dis(vec[j], vec[c]))));
            mn = min(mx, 2 * (k + min(dis(vec[i], vec[c]), dis(vec[j], vec[c]))));
        }
    }
    cout << mx - mn << "\n";
}

