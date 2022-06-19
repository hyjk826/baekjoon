// 2022-06-19
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

vi graph[200001];

int main(){
    fastio;
	int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a;
        while(cin >> a){
            if(a == 0) break;
            a--;
            graph[i].push_back(a);
        }
    }
    int m;
    cin >> m;
    queue<int> Q;
    vi degree(n);
    vi ans(n, -1);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        a--;
        Q.push(a);
        ans[a] = 0;
        for(auto& j : graph[a]){
            degree[j]++;
        }
    }
    while(!Q.empty()){
        int s = (int)Q.size();
        vi vec;
        while(s--){
            int x{Q.front()};
            Q.pop();
            for(auto& v : graph[x]){
                if(ans[v] != -1) continue;
                if(degree[v] * 2 >= graph[v].size()){
                    ans[v] = ans[x] + 1;
                    Q.push(v);
                    vec.push_back(v);
                }
            }
        }
        for(auto& i : vec){
            for(auto& j : graph[i]){
                degree[j]++;
            }
        }
    }
    for(auto& i : ans) cout << i << " ";
}