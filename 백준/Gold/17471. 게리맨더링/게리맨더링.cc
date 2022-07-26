// 2022-07-26
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

vi g[11];

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    int sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
    }
    for(int i{0}; i < n; ++i){
        int c;
        cin >> c;
        for(int j{0}; j < c; ++j){
            int a;
            cin >> a;
            a--;
            g[i].push_back(a);
            g[a].push_back(i);
        }
    }
    int ans{MAX};
    for(int i{0}; i < (1 << n); ++i){
        set<int> s;
        set<int> s2;
        for(int j{0}; j < n; ++j){
            if(i >> j & 1) s.insert(j);
            else s2.insert(j);
        }
        if(s.size() == 0 || s2.size() == 0) continue;
        int cnt{0};
        int sum2{0};
        vi ch(n);
        int a = *(s.begin());
        ch[a] = 1;
        queue<int> Q;
        Q.push(a);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            cnt++;
            sum2 += vec[x];
            for(auto& j : g[x]){
                if(s.count(j) && ch[j] == 0){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
        int cnt2{0};
        for(int i{0}; i < n; ++i) ch[i] = 0;
        a = *(s2.begin());
        ch[a] = 1;
        Q.push(a);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            cnt2++;
            for(auto& j : g[x]){
                if(s2.count(j) && ch[j] == 0){
                    ch[j] = 1;
                    Q.push(j);
                }
            }
        }
        if(cnt == (int)s.size() && cnt2 == (int)s2.size() && sum != sum2){
            ans = min(ans, abs(sum - sum2 - sum2));
        }
    }
    if(ans == MAX) cout << -1;
    else cout << ans;
}

