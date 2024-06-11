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
	int n; 
    cin >> n;
    vp vec(n);
    for(auto& i : vec) cin >> i.first >> i.second;
    int ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            for(int k{j + 1}; k < n; ++k){
                int x1 = vec[i].first; int y1 = vec[i].second;
                int x2 = vec[j].first; int y2 = vec[j].second;
                int x3 = vec[k].first; int y3 = vec[k].second;
                ans = max(ans, abs(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2));
            }
        }
    }
    if(ans & 1) cout << ans / 2 << ".5\n";
    else cout << ans / 2 << "\n";
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