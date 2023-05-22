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
    int a, b, c;
    cin >> a >> b >> c;
    vector<vi> g1(n + 1), g2(n + 1), g3(n + 1);
    for(int i{0}; i < a; ++i){
        int x, y;
        cin >> x >> y;
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
    for(int i{0}; i < b; ++i){
        int x, y;
        cin >> x >> y;
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    for(int i{0}; i < c; ++i){
        int x, y;
        cin >> x >> y;
        g3[x].push_back(y);
        g3[y].push_back(x);
    }
    map<vi, vi> mp;
    vector<vi> color(n + 1);
    vi ch1(n + 1), ch2(n + 1), ch3(n + 1);
    int cnt{0};
    for(int i{1}; i <= n; ++i){
        if(ch1[i]) continue;
        cnt++;
        queue<int> Q;
        Q.push(i);
        ch1[i] = 1;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            color[x].push_back(cnt);
            for(auto& j : g1[x]){
                if(ch1[j] == 0){
                    ch1[j] = 1;
                    Q.push(j);
                }
            }
        }
    }
    cnt = 0;
    for(int i{1}; i <= n; ++i){
        if(ch2[i]) continue;
        cnt++;
        queue<int> Q;
        Q.push(i);
        ch2[i] = 1;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            color[x].push_back(cnt);
            for(auto& j : g2[x]){
                if(ch2[j] == 0){
                    ch2[j] = 1;
                    Q.push(j);
                }
            }
        }
    }
    cnt = 0;
    for(int i{1}; i <= n; ++i){
        if(ch3[i]) continue;
        cnt++;
        queue<int> Q;
        Q.push(i);
        ch3[i] = 1;
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            color[x].push_back(cnt);
            for(auto& j : g3[x]){
                if(ch3[j] == 0){
                    ch3[j] = 1;
                    Q.push(j);
                }
            }
        }
    }
    for(int i{1}; i <= n; ++i){
        mp[color[i]].push_back(i);
    }
    vector<vi> ans;
    for(auto& i : mp){
        if(i.second.size() == 1) continue;
        ans.push_back(i.second);
    }
    sort(ans.begin(), ans.end(), [&](vi& x, vi& y){
        return x.front() < y.front();
    });
    cout << ans.size() << "\n";
    for(auto& i : ans){
        for(auto& j : i) cout << j << " ";
        cout << "\n";
    }
}
