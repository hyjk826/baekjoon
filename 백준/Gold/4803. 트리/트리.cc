// 2022-07-07
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

vi graph[500];

int main(){
    fastio;
    int t{1};
	while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0) break;        
        for(int i{0}; i < n; ++i){
            graph[i].clear();
        }
        for(int i{0}; i < m; ++i){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ans{0};
        vi ch(n);
        for(int i{0}; i < n; ++i){
            if(ch[i] == 0){
                ch[i] = 1;
                queue<int> Q;
                Q.push(i);
                bool flag = true;
                vi v;
                while(!Q.empty()){
                    int x{Q.front()};
                    Q.pop();
                    v.push_back(x);
                    for(auto& j : graph[x]){
                        if(ch[j] == 0){
                            ch[j] = 1;
                            Q.push(j);
                        }
                    }
                }
                int sum{0};
                for(auto& j : v){
                    sum += (int)graph[j].size();
                }
                int k = (int)v.size();
                if(sum == (k - 1) * 2) ans++;
            }
        }
        cout << "Case " << t << ": ";
        if(ans == 0){
            cout << "No trees.\n";
        }
        else if(ans == 1){
            cout << "There is one tree.\n";
        }
        else{
            cout << "A forest of " << ans << " trees.\n";
        }
        t++;
    }
}