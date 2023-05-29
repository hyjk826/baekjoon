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

double dist(int x1, int y1, int x2, int y2){
	int x = x1 - x2;
	int y = y1 - y2;
	return sqrt(x * x + y * y);
}

int main(){
	fastio;
	int n;
	cin >> n;
	vp vec(n);
	for(int i{0}; i < n; ++i){
		cin >> vec[i].first >> vec[i].second;
	}
	double ans{0};
	for(int i{0}; i < n; ++i){
		for(int j{0}; j < n; ++j){
			if(i == j) continue;
			ans += dist(vec[i].first, vec[i].second, vec[j].first, vec[j].second);
		}
	}
	ans /= n;
	cout << fixed << setprecision(20);
	cout << ans;
}
