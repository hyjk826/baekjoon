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
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

struct st{
    int v, w;
    bool operator< (const st& a) const{
        return w > a.w;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int a, b;
    cin >> a >> b;
    vi A(a), B(b);
    priority_queue<st> pQ;
    vi dist(n, MAX);
    for(int i{0}; i < a; ++i){
        int x, y;
        cin >> x >> y;
        x--;
        dist[x] = -y;
        pQ.push({x, -y});
    }
    vi ch(n);
    for(int i{0}; i < b; ++i){
        int x, y;
        cin >> x >> y;
        x--;
        ch[x] = y;
    }
    while(!pQ.empty()){
        int v{pQ.top().v};
        int w{pQ.top().w};
        pQ.pop();
        if(dist[v] < w) continue;
        for(int i{0}; i < n; ++i){
            if(board[v][i] == 0) continue;
            if(dist[i] > board[v][i] + w){
                dist[i] = board[v][i] + w;
                pQ.push({i, dist[i]});
            }
        }
    }
    int ans{MAX};
    for(int i{0}; i < n; ++i){
        if(ch[i]){
            ans = min(ans, dist[i] - ch[i]);
        }
    }
    cout << -ans;
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
