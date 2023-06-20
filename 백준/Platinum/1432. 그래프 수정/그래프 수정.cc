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

void solve(){
    int n;
    cin >> n;
    vector<vi> g(n);
    vi degree(n);
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            char a;
            cin >> a;
            if(a == '1'){
                g[j].push_back(i);
                degree[i]++;
            }
        }
    }
    priority_queue<int> pQ;
    for(int i{0}; i < n; ++i){
        if(degree[i] == 0) pQ.push(i);
    }
    vi ans(n);
    int cnt{n};
    while(!pQ.empty()){
        int x{pQ.top()};
        pQ.pop();
        ans[x] = cnt;
        cnt--;
        for(auto& i : g[x]){
            degree[i]--;
            if(degree[i] == 0){
                pQ.push(i);
            }
        }
    }
    if(cnt == 0){
        for(auto& i : ans) cout << i << " ";
    }
    else cout << -1;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
