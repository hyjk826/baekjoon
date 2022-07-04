// 2022-07-05
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi graph[100001];
vi ans(100001);

int main(){
    fastio;
    int n, m, s;
    cin >> n >> m >> s;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i{1}; i <= n; ++i){
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    queue<int> Q;
    Q.push(s);
    int cnt{1};
    ans[s] = cnt++;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : graph[x]){
            if(ans[i] == 0){
                ans[i] = cnt++;
                Q.push(i);
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << "\n";
    }
}