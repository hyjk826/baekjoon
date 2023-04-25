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
    for(int i{1}; i <= n; ++i){
        int k;
        cin >> k;
        for(int j{0}; j < k; ++j){
            int a;
            cin >> a;
            g[i].push_back(a);
            g[a].push_back(i);
        }
    }
    vi ch(n + 1, -1);
    for(int i{1}; i <= n; ++i){
        if(ch[i] != -1) continue;
        queue<int> Q;
        Q.push(i);
        ch[i] = 0;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            for(auto& i : g[x]){
                if(ch[i] == -1){
                    ch[i] = ch[x] ^ 1;
                    Q.push(i);
                }
            }
        }
    }
    vi A, B;
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0) A.push_back(i);
        else B.push_back(i);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    cout << A.size() << "\n";
    for(auto& i : A) cout << i << " ";
    cout << "\n";
    cout << B.size() << "\n";
    for(auto& i : B )cout << i << " ";
}
