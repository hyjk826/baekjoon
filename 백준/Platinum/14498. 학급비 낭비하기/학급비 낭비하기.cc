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
    int n, m, k;
    cin >> n >> m >> k;
    vi match(k, -1);
    vi ch(k);
    vector<vi> g(k);
    vector<vi> board(k, vi(3));
    for(int i{0}; i < k; ++i){
        for(int j{0}; j < 3; ++j){
            cin >> board[i][j];
        }
    }
    function<bool(int)> bipartiteMatching = [&](int a){
        for(auto& i : g[a]){
            if(ch[i] == 0){
                ch[i] = 1;
                if(match[i] == -1 || bipartiteMatching(match[i])){
                    match[i] = a;
                    return true;
                }
            }
        }
        return false;
    };
    for(int i{0}; i < k; ++i){
        for(int j{i + 1}; j < k; ++j){
            if(board[i][2] != board[j][2] && (board[i][0] == board[j][0] || board[i][1] == board[j][1])){
                if(board[i][2]) g[j].push_back(i);
                else g[i].push_back(j);
            }
        }
    }
    int ans{0};
    for(int i{0}; i < k; ++i){
        fill(ch.begin(), ch.end(), 0);
        if(bipartiteMatching(i)) ans++;
    }
    cout << ans;
}
