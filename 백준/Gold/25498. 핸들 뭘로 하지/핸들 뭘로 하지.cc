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
    string str;
    cin >> str;
    str = ' ' + str;
    vector<vi> g(n + 1);
    for(int i{0}; i < n - 1; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    string ans;
    ans += str[1];
    vi ch(n + 1);
    ch[1] = 1;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int sz = (int)Q.size();
        char c = 'a' - 1;
        for(int i{0}; i < sz; ++i){
            int x{Q.front()};
            Q.pop();
            for(auto& j : g[x]){
                if(ch[j] == 0){
                    c = max(c, str[j]);
                }
            }
            Q.push(x);
        }
        if(c == 'a' - 1) break;
        else ans += c;
        for(int i{0}; i < sz; ++i){
            int x{Q.front()};
            Q.pop();
            for(auto& j : g[x]){
                if(ch[j] == 0 && str[j] == c){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
    }
    cout << ans;
}
	

