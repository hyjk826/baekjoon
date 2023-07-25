// 2022-09-16
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

int main() {
	fastio;
    int n;
    cin >> n;
    vi degree(n);
    map<string, int> mp;
    vector<vi> g(n);
    int k{0};
    for(int i{0}; i < n - 1; ++i){
        string s, t;
        cin >> s >> t;
        if(!mp.count(s)) mp[s] = k++;
        if(!mp.count(t)) mp[t] = k++;
        int a = mp[s];
        int b = mp[t];
        g[b].push_back(a);
        degree[a]++;
    }
    int root;
    for(int i{0}; i < n; ++i){
        if(degree[i] == 0) root = i;
    }
    string s, t;
    cin >> s >> t;
    vi depth(n, -1);
    vi p(n, -1);
    queue<int> Q;
    Q.push(root);
    depth[root] = 0;
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        for(auto& i : g[x]){
            if(depth[i] == -1){
                depth[i] = depth[x] + 1;
                p[i] = x;
                Q.push(i);
            }
        }
    }
    int a = mp[s];
    int b = mp[t];
    bool flag = false;
    if(depth[a] < depth[b]){
        for(int i{b}; i != -1; i = p[i]){
            if(i == a){
                flag = true;
                break;
            }
        }
    }
    else{
        for(int i{a}; i != -1; i = p[i]){
            if(i == b){
                flag = true;
                break;
            }
        }
    }
    if(flag) cout << 1;
    else cout << 0;
}
	

