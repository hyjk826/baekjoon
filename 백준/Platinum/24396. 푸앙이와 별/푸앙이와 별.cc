// 2022-12-15
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
    int n, m;
    cin >> n >> m;
    set<int> st;
    set<pi> RemovedEgge;
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        RemovedEgge.insert({min(a, b), max(a, b)});
    }
    vi ans(n + 1, -1);
    for(int i{2}; i <= n; ++i){
        st.insert(i);
    }
    ans[1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int x{Q.front()};
        Q.pop();
        vi A;
        for(auto& i : st){
            if(!RemovedEgge.count({min(x, i), max(x, i)})){
                A.push_back(i);
                ans[i] = ans[x] + 1;
            }
        }
        for(auto& i : A) {
            if(st.count(i)){
                st.erase(i);
                Q.push(i);
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        cout << ans[i] << "\n";
    }
}
	
