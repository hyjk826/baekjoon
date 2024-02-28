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
#define MOD 998244353
using namespace std; 


void solve(){
	int n;
    cin >> n;
    vector<vi> board(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int l{0}, r{(int)1e6};
    int ans{-1};
    while(l <= r){
        int mid{(l + r) >> 1};
        vector<vi> g(n);
        for(int i{0}; i < n; ++i){
            for(int j{i + 1}; j < n; ++j){
                if(board[i][j] < mid){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        bool ok = true;
        vi ch(n, -1);
        for(int i{0}; i < n; ++i){
            if(ch[i] != -1) continue;
            ch[i] = 0;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int x{Q.front()};
                Q.pop();
                for(auto& i : g[x]){
                    if(ch[i] == -1){
                        ch[i]= ch[x] ^ 1;
                        Q.push(i);
                    }
                    else{
                        if(ch[i] == ch[x]){
                            ok = false; break;
                        }                        
                    }
                }
                if(!ok) break;
            }
        }
        if(ok){
            ans = mid;
            l = mid + 1;
        }
        else r = mid- 1;
    }
    cout << ans << "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}