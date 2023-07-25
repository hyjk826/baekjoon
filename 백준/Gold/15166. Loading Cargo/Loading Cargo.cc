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
	int L, R, n, C;
    cin >> L >> R >> n >> C;
    if(L + R < n){
        cout << "No"; return;
    }
    vector<vi> g(n);
    for(int i{0}; i < C; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }   
    vi ch(n, -1);
    vp A;
    int sum{0};
    for(int i{0}; i < n; ++i){
        if(ch[i] != -1) continue;
        ch[i] = 0;
        queue<int> Q;
        Q.push(i);
        vi cnt(2);
        while(!Q.empty()){
            int x{Q.front()};
            Q.pop();
            cnt[ch[x]]++;
            for(auto& i : g[x]){
                if(ch[i] == -1){
                    ch[i] = ch[x] ^ 1;                    
                    Q.push(i);
                }
                else{
                    if(ch[i] == ch[x]){
                        cout << "No"; return;
                    }
                }
            }
        }
        A.push_back({cnt[0], cnt[1]});
        sum += cnt[0];
        sum += cnt[1];
    }
    vector<vi> dp((int)A.size() + 1, vi(n + 1));
    dp[0][0] = 1;
    for(int i{0}; i < (int)A.size(); ++i){
        for(int j{0}; j < n; ++j){
            if(dp[i][j]) {
                dp[i + 1][j + A[i].first] = 1;
                dp[i + 1][j + A[i].second] = 1;
            }
        }
    }
    for(int i{0}; i <= n; ++i){
        if(dp[(int)A.size()][i] == 0) continue;
        int a = i;
        int b = sum - i;
        if((a <= L && b <= R) || (b <= L && a <= R)){
            cout << "Yes"; return;
        }
    }
    cout << "No";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}