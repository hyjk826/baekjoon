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

int main(){
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vi> g(n + 1);
        vi degree(n + 1);
        for(int i{0}; i < n - 1; ++i){
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        bool flag = true;
        int idx{-1};
        for(int i{1}; i <= n; ++i){
            if(degree[i] == n - 1) flag = false;
            if(degree[i] >= 2) idx = i;
        }
        if(!flag) cout << -1 << "\n";
        else{
            vi in(n + 1), out(n + 1);
            queue<int> Q;
            Q.push(idx);
            vi depth(n + 1, -1);
            depth[idx] = 0;
            vi A, B;
            vi p(n + 1);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                if(depth[x] % 2 == 0) A.push_back(x);
                else B.push_back(x);
                for(auto& i : g[x]){
                    if(depth[i] == -1){
                        p[i] = x;
                        depth[i] = depth[x] + 1;
                        Q.push(i);
                    }
                }
            }
            if(p[A.back()] == B.front()) swap(B[0], B[1]);
            for(auto& i : A) cout << i << " ";
            for(auto& i : B) cout << i << " ";
            cout << "\n";
        }
    }
}
