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

struct st{
    int x, y, w;
};

void solve(){
    int n;
    cin >> n;
    vector<st> vec(n);
    vi X, Y;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].x >> vec[i].y >> vec[i].w;
        X.push_back(vec[i].x);
        Y.push_back(vec[i].y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    int ans{n};
    for(int i{0}; i < n; ++i){
        for(int j{i}; j < n; ++j){
            for(int a{0}; a < n; ++a){
                for(int b{a}; b < n; ++b){
                    int cnt{0};
                    vi tmp;
                    int sum{0};
                    int need = 2 * (X[j] - X[i]) + 2 * (Y[b] - Y[a]);
                    for(int k{0}; k < n; ++k){
                        if(X[i] <= vec[k].x && vec[k].x <= X[j] && Y[a] <= vec[k].y && vec[k].y <= Y[b]) tmp.push_back(vec[k].w);
                        else {
                            need -= vec[k].w; 
                            cnt++;
                        }
                    }
                    sort(tmp.begin(), tmp.end());
                    while(!tmp.empty() && need > 0){
                        need -= tmp.back();
                        tmp.pop_back();
                        cnt++;
                    }
                    if(need <= 0) ans = min(ans, cnt);
                }
            }
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
