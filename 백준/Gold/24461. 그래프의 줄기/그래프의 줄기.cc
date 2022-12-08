// 2022-12-08
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

int main() {
	fastio;
	int n;
    cin >> n;
    vector<vi> g((int)1e5 + 10);
    vi degree((int)1e5 + 10);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    vi ch((int)1e5 + 10);
    queue<int> Q;
    for(int i{0}; i < n; ++i){
        if(degree[i] == 1) Q.push(i);
        ch[degree[i]]++;
    }
    int cnt{n};
    vi ch2((int)1e5 + 10, 1);
    while(1){
        if(ch[1] <= 2){
            for(int i{0}; i < n; ++i){
                if(ch2[i]){
                    cout << i << " ";
                }
            }
            return 0;
        }
        int sz = (int)Q.size();
        for(int i{0}; i < sz; ++i){
            int x{Q.front()};
            Q.pop();
            cnt--;
            ch[1]--;
            ch2[x] = 0;
            degree[x] = 0;
            for(auto& i : g[x]){
                if(ch2[i] == 0) continue;
                degree[i]--;
                ch[degree[i] + 1]--;
                ch[degree[i]]++;
                if(degree[i] == 1) Q.push(i);
            }
        }
    }
}
	
