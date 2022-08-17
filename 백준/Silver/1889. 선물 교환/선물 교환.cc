// 2022-08-17
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
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

vi g[200000];

int main() {
	fastio;
    int n;
    cin >> n;
    vi degree(n);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        degree[a]++;
        degree[b]++;
        g[i].push_back(a);
        g[i].push_back(b);
    }
    vi ans;
    queue<int> Q;
    for(int i{0}; i < n; ++i){
        if(degree[i] <= 1) Q.push(i);
    }
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            degree[i]--;
            if(degree[i] == 1){
                Q.push(i);
            }
        }
    }
    for(int i{0}; i < n; ++i){
        if(degree[i]) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for(auto& i : ans){
        cout << i + 1 << " ";
    }
}