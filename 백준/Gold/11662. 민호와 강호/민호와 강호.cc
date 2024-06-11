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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

double dist(pair<double, double> a, pair<double, double> b){
    double x = a.first - b.first;
    double y = a.second - b.second;
    return x * x + y * y;
}

void solve(){
	vector<pair<double, double>> vec(4);
    for(int i{0}; i < 4; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    double l{0}, r{1};
    double ans{-1};
    while(r - l > 1e-10){
        double l2 = (l + l + r) / 3;
        double r2 = (l + r + r) / 3;
        pair<double,double> a = {vec[0].first + (vec[1].first - vec[0].first) * l2, vec[0].second + (vec[1].second - vec[0].second) * l2};
        pair<double,double> b = {vec[2].first + (vec[3].first - vec[2].first) * l2, vec[2].second + (vec[3].second - vec[2].second) * l2};
        pair<double,double> c = {vec[0].first + (vec[1].first - vec[0].first) * r2, vec[0].second + (vec[1].second - vec[0].second) * r2};
        pair<double,double> d = {vec[2].first + (vec[3].first - vec[2].first) * r2, vec[2].second + (vec[3].second - vec[2].second) * r2};
        if(dist(a, b) <= dist(c, d)){
            ans = sqrt(dist(a, b));
            r = r2;
        }
        else{
            ans = sqrt(dist(c, d));
            l = l2;
        }
    }
    cout << fixed << setprecision(20);
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
