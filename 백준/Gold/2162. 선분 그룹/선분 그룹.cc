// 2022-09-15
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

int ccw(pi a, pi b, pi c){
    int op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if(op > 0) return 1;
    else if(op == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pi, pi> x, pair<pi, pi> y){
    pi a = x.first;
    pi b = x.second;
    pi c = y.first;
    pi d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
	fastio;
    int n;
    cin >> n;
    vector<pair<pi, pi> > vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first.first >> vec[i].first.second >> vec[i].second.first >> vec[i].second.second;
    }
    vector<vi> g(n);
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            if(isIntersect(vec[i], vec[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vi ch(n);
    vi ans;
    for(int i{0}; i < n; ++i){
        if(ch[i] == 0){
            ch[i] = 1;
            queue<int> Q;
            Q.push(i);
            int cnt{0};
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                cnt++;
                for(auto& j : g[x]){
                    if(ch[j] == 0){
                        ch[j] = 1;
                        Q.push(j);
                    }
                }
            }
            ans.push_back(cnt);
        }
    }
    if(ans.size() == 0){
        cout << 0 << "\n" << 0;
        return 0;
    }
    cout << ans.size() << "\n";
    cout << *max_element(ans.begin(), ans.end());
}
	

