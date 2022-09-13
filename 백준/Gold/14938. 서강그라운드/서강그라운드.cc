// 2022-09-13
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

vector<st> graph[101];

int main(){
    fastio;
	int n, m, k;
    cin >> n >> k >> m;
    vi score(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> score[i];
    }
    for(int i{0}; i < m; ++i){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    int ans{0};
    for(int i{1}; i <= n; ++i){
        vi dijk(n + 1, MAX);
        dijk[i] = 0;
        priority_queue<st> pQ;
        pQ.push({i, 0});
        while(!pQ.empty()){
            int v{pQ.top().v};
            int w{pQ.top().w};
            pQ.pop();
            if(dijk[v] < w) continue;
            for(auto& u : graph[v]){
                int nv = u.v;
                int nw = u.w;
                if(dijk[nv] > dijk[v] + nw){
                    dijk[nv] = dijk[v] + nw;
                    pQ.push({nv, dijk[nv]});
                }
            }
        }
        int sum{0};
        for(int j{1}; j <= n; ++j){
            if(dijk[j] <= k){
                sum += score[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
}
	

