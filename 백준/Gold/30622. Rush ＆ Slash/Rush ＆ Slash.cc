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

int xx[]{-1,-1,-1,0,0,1,1,1};
int yy[]{-1,0,1,-1,1,-1,0,1};

void solve(){
	int n;
    cin >> n;
    set<pi> st;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        st.insert({vec[i].first, vec[i].second});
    }
    vi tmp;
    ll ans{0};
    while(!st.empty()){
        queue<pi> Q;
        Q.push({st.begin()->first, st.begin()->second});
        st.erase(st.begin());
        int mn{MAX};
        while(!Q.empty()){
            int x{Q.front().first};
            int y{Q.front().second};
            Q.pop();
            mn = min(mn, abs(x) + abs(y));
            for(int dir{0}; dir < 8; ++dir){
                int nx{x + xx[dir]};
                int ny{y + yy[dir]};
                if(st.count({nx, ny})){
                    st.erase({nx, ny});
                    Q.push({nx, ny});
                }
            }
        }
        tmp.push_back(mn);
    }
    cout << 2 * accumulate(tmp.begin(), tmp.end(), 0LL) - *max_element(tmp.begin(), tmp.end()) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
