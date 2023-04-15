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
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    int root;
    for(int i{1}; i <= n; ++i){
        int p;
        cin >> p;
        if(p == -1) {
            root = i; continue;
        }
        g[p].push_back(i);
    }
    vi num(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> num[i];
    }
    vi A;
    queue<int> Q;
    Q.push(root);
    vi ch(n + 1);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        A.push_back(x);
        for(auto& i : g[x]){
            if(ch[i] == 0){
                ch[i] = 1;
                Q.push(i);
            }
        }
    }
    vector<set<int> > vec(n + 1);
    vi ans(n + 1);
    fill(ch.begin(), ch.end(), 0);
    for(int i{n - 1}; i >= 0; --i){
        if(g[A[i]].size() == 0){
            if(num[A[i]] == 0) ans[A[i]] = 1;
            vec[A[i]].insert(num[A[i]]);
            ch[A[i]] = A[i];
        }
        else{
            sort(g[A[i]].begin(), g[A[i]].end(), [&](int a, int b){
                return vec[ch[a]].size() > vec[ch[b]].size();
            });
            int mx{0};
            for(auto& j : g[A[i]]){
                mx = max(mx, ans[j]);
            }
            for(int j{1}; j < (int)g[A[i]].size(); ++j){
                for(auto& k : vec[ch[g[A[i]][j]]]){
                    vec[ch[g[A[i]][0]]].insert(k);
                }
            }
            vec[ch[g[A[i]][0]]].insert(num[A[i]]);
            while(vec[ch[g[A[i]][0]]].count(mx)) mx++;
            ans[A[i]] = mx;
            ch[A[i]] = ch[g[A[i]][0]];
        }
    }
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << "\n";
    }
}
