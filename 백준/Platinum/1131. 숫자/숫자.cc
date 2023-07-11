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

int pow(int a, int b){
    int ret{1};
    for(int i{0}; i < b; ++i) ret *= a;
    return ret;
}



int f(int a, int k){
    int ret{0};
    while(a){
        int x = a % 10;
        ret += pow(x, k);
        a /= 10;
    }
    return ret;
}

vector<vi> g(3188647);
int dp[3188647];

void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    memset(dp, -1, sizeof(dp));
    queue<int> Q;
    for(int i{1};i <= 6 * pow(9, 6); ++i){
        g[f(i, k)].push_back(i);
    }
    for(int i{1}; i <= 3188646; ++i){
        if(dp[i] != -1) continue;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            dp[x] = i;
            for(auto& j : g[x]){
                if(dp[j] != -1) continue;
                if(j > i){
                    Q.push(j);
                }
            }
        }
    }
    ll ans{0};
    for(int i{a}; i <= b; ++i){
        ans += dp[i];
    }
    cout << ans;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
