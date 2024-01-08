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

int ccw(pl a, pl b, pl c){
    ll op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pl, pl> x, pair<pl, pl> y){
    pl a = x.first;
    pl b = x.second;
    pl c = y.first;
    pl d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c < b && a < d;
    }
    return ab < 0 && cd < 0;
}

double dist(pi A, pi B){
	int x = A.first - B.first;
	int y = A.second - B.second;
	return sqrt(1LL * x * x + 1LL * y * y);
}

void solve(){
	int n;
	cin >> n;
	vp vec(n);
	for(int i{0}; i < n; ++i){
		cin >> vec[i].first >> vec[i].second;
	}
	vi order(n);
	iota(order.begin(), order.end(), 0);	
	double ans = 1e18;
	do{
		bool ok = true;
		for(int i{0}; i < n; ++i){
			for(int j{0}; j < n; ++j){
				if(i == j) continue;
				if(isIntersect({vec[order[i]], vec[order[(i + 1) % n]]}, {vec[order[j]], vec[order[(j + 1) % n]]})){
					ok = false;
					break;
				}
			}
			if(!ok) break;
		}
		double k = 0;
		for(int i{0}; i < n; ++i){
			k += dist(vec[order[i]], vec[order[(i + 1) % n]]);
		}
		ans = min(ans, k);
	}while(next_permutation(order.begin(), order.end()));
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
