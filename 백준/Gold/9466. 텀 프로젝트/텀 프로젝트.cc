// 2022-09-14
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

vi vec;
vi g[100001];
vi ch(100001);
vi finish(100001);
void isHaveCycle(int v){
    ch[v] = 1;
    for(auto& u : g[v]){
        if(ch[u] == 0){
            isHaveCycle(u);
        }
        else if(!finish[u]){
            vec.push_back(u);
        }
    }
    finish[v] = 1;
}



int main() {
	fastio;
    int t;
    cin >> t;    
    while(t--){
        int n;
        cin >> n;
        vec.clear();
        for(int i{1}; i <= n; ++i){
            ch[i] = 0;
            finish[i] = 0;
            g[i].clear();
            int a;
            cin >> a;
            g[i].push_back(a);
        }
        for(int i{1}; i <= n; ++i){
            if(!ch[i]) isHaveCycle(i);
        }
        queue<int> Q;
        for(int i{1}; i <= n; ++i) ch[i] = 0;
        for(auto& i : vec){
            Q.push(i);
            ch[i] = 1;
        }
        vi ans;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            ans.push_back(x);
            for(auto& i : g[x]){
                if(ch[i] == 0){
                    ch[i] = 1;
                    Q.push(i);
                }
            }
        }
        cout << n - ans.size() << "\n";        
    }
}
	

