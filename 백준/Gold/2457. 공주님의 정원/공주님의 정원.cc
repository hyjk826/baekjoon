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

int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int f(int a, int b){
    int ret{b};
    for(int i{1}; i < a; ++i){
        ret += m[i];
    }
    return ret;
}

void solve(){
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vec[i] = {f(a, b), f(c, d) - 1};
    }
    sort(vec.begin(), vec.end());
    int idx{0};
    int ans{1};
    int r{-1};
    for(int i{0}; i < n; ++i){
        if(vec[i].first <= f(3, 1)){
            r = max(r, vec[i].second);
        }
    }
    priority_queue<int> pQ;
    while(r < f(11, 30)){
        while(idx < n && vec[idx].first <= r + 1){
            pQ.push(vec[idx++].second);
        }
        if(!pQ.empty() && r != pQ.top()){
            r = pQ.top();
            ans++;
        }
        else break;
    }
    if(r < f(11, 30)) ans = 0;
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
