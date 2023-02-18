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

vi match(2500, -1);
vi ch(2500);
vector<vi> g(2500);

bool bipartiteMatching(int x){
    for(auto& i : g[x]){
        if(ch[i] == 0){
            ch[i] = 1;
            if(match[i] == -1 || bipartiteMatching(match[i])){
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int cnt{0};
    vector<vi> A(n, vi(m)), B(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == '*') A[i][j] = cnt;
            if(j == m - 1 || board[i][j + 1] == '.') cnt++;
        }
    }
    cnt = 0;
    for(int j{0}; j < m; ++j){
        for(int i{0}; i < n; ++i){
            if(board[i][j] == '*') B[i][j] = cnt;
            if(i == n - 1 || board[i + 1][j] == '.') cnt++;
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            if(board[i][j] == '*'){
                g[A[i][j]].push_back(B[i][j]);
            }
        }
    }
    int ans{0};
    for(int i{0}; i < 2500; ++i){
        fill(ch.begin(), ch.end(), 0);
        if(bipartiteMatching(i)) ans++;
    }
    cout << ans;
}
