// 2022-03-06
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vp vector<pair<int, int> >
#define pi pair<int, int>
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    set<int> s;
    int x;
    cin >> x;
    for(int i{0}; i < x; ++i){
        int a;
        cin >> a;
        s.insert(a);
    }
    vi party[51];
    vi P[51];
    vi graph[51];
    for(int i{1}; i <= m; ++i){
        int a;
        cin >> a;
        for(int j{0}; j < a; ++j){
            int p;
            cin >> p;
            party[i].push_back(p);
            P[p].push_back(i);
        }
    }
    // for(int i{1}; i <= n; ++i){
    //     cout << i << " ";
    //     for(int j{0}; j < (int)P[i].size(); ++j){
    //         cout << P[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j < (int)P[i].size(); ++j){
            graph[P[i][0]].push_back(P[i][j]);
            graph[P[i][j]].push_back(P[i][0]);
        }
    }
    vi ch(m + 1);
    int ans{0};
    for(int i{1}; i <= m; ++i){
        if(ch[i] == 0){
            queue<int> Q;
            Q.push(i);
            ch[i] = 1;
            vi v;
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                v.push_back(x);
                for(int j{0}; j < (int)graph[x].size(); ++j){
                    int nx = graph[x][j];
                    if(ch[nx] == 0){
                        ch[nx] = 1;
                        Q.push(nx);
                    }
                }
            }
            bool flag = true;
            for(int j{0}; j < (int)v.size(); ++j){
                for(int k{0}; k < (int)party[v[j]].size(); ++k){
                    if(s.count(party[v[j]][k]) == 1){
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag){
                ans += v.size();
            }
        }
    }
    cout << ans;
}