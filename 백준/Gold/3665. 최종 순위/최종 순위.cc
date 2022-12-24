// 2022-12-24
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
        vi rank(n + 1);
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
            rank[vec[i]] = i + 1;
        }
        int m;
        cin >> m;
        vp A(m);
        vector<vi> g(n + 1);
        vi degree(n + 1);
        vector<vi> ch(n + 1, vi(n + 1));
        for(int i{0}; i < m; ++i){
            cin >> A[i].first >> A[i].second;
            ch[A[i].first][A[i].second] = ch[A[i].second][A[i].first] = 1;
            if(rank[A[i].first] < rank[A[i].second]) {
                g[A[i].second].push_back(A[i].first);
                degree[A[i].first]++;
            }
            else{ 
                g[A[i].first].push_back(A[i].second);
                degree[A[i].second]++;
            }
        }
        for(int i{0}; i < n; ++i){
            for(int j{i + 1}; j < n; ++j){
                if(ch[vec[i]][vec[j]]) continue;
                g[vec[i]].push_back(vec[j]);
                degree[vec[j]]++;
            }
        }
        queue<int> Q;
        for(int i{1}; i <= n; ++i){
            if(degree[i] == 0) Q.push(i);
        }
        vi ans;
        bool ok = true;
        while(!Q.empty()){
            if(Q.size() >= 2) {
                ok = false;
                break;
            }
            int x{Q.front()};
            Q.pop();
            ans.push_back(x);
            for(auto& i : g[x]){
                degree[i]--;
                if(degree[i] == 0){
                    Q.push(i);
                }
            }
        }
        if(ans.size() == n){
            for(auto& i : ans) cout << i << " ";
            cout << "\n";
        }
        else{
            if(ok) cout << "IMPOSSIBLE\n";
            else cout << "?\n";
        }
    }
}
