#include <bits/stdc++.h>
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

void solve(){
	int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vp vec(n);
    for(auto& i : vec) cin >> i.first >> i.second;

    function<bool(pi, pi)> f = [&](pi a, pi b){

        if (a.first > h || a.second > w) return false;

        if(b.first <= h && b.second <= w - a.second) return true;
        if(b.first <= h - a.first && b.second <= w) return true;

        return false; 
    };

    int ans{0};

    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            if(f({vec[i].first, vec[i].second}, {vec[j].first, vec[j].second})) ans = max(ans, vec[i].first * vec[i].second + vec[j].first * vec[j].second);
            if(f({vec[i].first, vec[i].second}, {vec[j].second, vec[j].first})) ans = max(ans, vec[i].first * vec[i].second + vec[j].first * vec[j].second);
            if(f({vec[i].second, vec[i].first}, {vec[j].first, vec[j].second})) ans = max(ans, vec[i].first * vec[i].second + vec[j].first * vec[j].second);
            if(f({vec[i].second, vec[i].first}, {vec[j].second, vec[j].first})) ans = max(ans, vec[i].first * vec[i].second + vec[j].first * vec[j].second);
        }
    }

    cout << ans << "\n";

}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int T;
	T = 1;
	while(T--){
		solve();
	}
}