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

void solve(){
	int n;
    cin >> n;
    vs vec(n);
    vi ch(26);
    vi degree(26);
    set<pi> st;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        for(auto& j : vec[i]) ch[j - 'a'] = 1;
    }
    vector<vi> g(26);
    for(int i{0}; i < n - 1; ++i){
        int sz = min(vec[i].size(), vec[i + 1].size());
        int idx{0};
        while(idx < sz && vec[i][idx] == vec[i + 1][idx]) idx++;
        if(idx < sz) {
            int a = vec[i][idx] - 'a';
            int b = vec[i + 1][idx] - 'a';
            if(st.count({a, b})) continue;
            st.insert({a, b});
            g[a].push_back(b);
            degree[b]++;
            continue;
        }
        if(vec[i].size() > vec[i + 1].size()){
            cout << "!\n"; return;
        }
    }
    vi ans;
    queue<int> Q;
    for(int i{0}; i < 26; ++i){
        if(ch[i] == 0 || degree[i]) continue;
        Q.push(i);
    }
    bool ok = true;
    while(!Q.empty()){
        if(Q.size() >= 2) ok = false;
        int x{Q.front()};
        Q.pop();
        ans.push_back(x);
        for(auto& i : g[x]){
            degree[i]--;
            if(degree[i] == 0){
                Q.push(i);
            }
        }
    }
    int cnt = count(ch.begin(), ch.end(), 1);
    if(cnt != (int)ans.size()) cout << "!\n";
    else{
        if(ok){
            for(auto& i : ans) cout << char('a' + i);
            cout << "\n";
        }
        else cout << "?\n";
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
