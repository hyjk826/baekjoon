// 2022-11-13
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

int n, m;
vector<vi> edge(1001, vi(1001));
vector<vi> g(1001);
vi ch(1001, -1);

int main() {
	fastio;    
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            if(i == j) continue;
            if(edge[i][j] == 0){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vp A;
    for(int i{1}; i <= n; ++i){
        if(ch[i] != -1) continue;
        vi cnt(2);
        queue<int> Q;
        Q.push(i);
        ch[i] = 0;
        cnt[0]++;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& i : g[x]){
                if(ch[i] == -1){
                    ch[i] = (ch[x] ^ 1);
                    cnt[ch[i]]++;
                    Q.push(i);
                }
                else{
                    if(ch[i] == ch[x]){
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
        A.push_back({cnt[0], cnt[1]});
    }
    set<int> st;
    st.insert(A[0].first);
    st.insert(A[0].second);
    for(int i{1}; i < (int)A.size(); ++i){
        set<int> temp;
        for(auto& j : st){
            temp.insert(j + A[i].first);
            temp.insert(j + A[i].second);
        }
        st = temp;
    }
    int ans{MAX};
    for(auto& i : st){
        ans = min(ans, abs(i - (n - i)));
    }
    cout << ans;
}
	

