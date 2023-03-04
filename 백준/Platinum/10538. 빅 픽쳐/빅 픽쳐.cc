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
 
 
vector<vi> ret(2000, vi(2000));
 
void solve(){
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    vector<vc> board1(n1, vc(m1));
    vector<vc> board2(n2, vc(m2));
    for(int i{0}; i < n1; ++i){
        for(int j{0}; j < m1; ++j){
            cin >> board1[i][j];
        }
    }
    for(int i{0}; i < n2; ++i){
        for(int j{0}; j < m2; ++j){
            cin >> board2[i][j];
        }
    }
    int a{0};
    for(int i{0}; i < n1; ++i){
        int b{0};
        for(int j{0}; j < m1; ++j){
            b = b * 3 + board1[i][j];
        }
        a = a * 5 + b;
    }
    int e{1};
    for(int i{0}; i < m1 - 1; ++i) e *= 3;
    for(int i{0}; i < n2; ++i){
        int h{0};
        for(int j{0}; j < m1; ++j){
            h = h * 3 + board2[i][j];
        }
        for(int j{m1}; j < m2; ++j){
            ret[i][j - m1] = h;
            h -= board2[i][j - m1] * e;
            h = h * 3 + board2[i][j];
        }
        ret[i][m2 - m1] = h;
    }
    int ans{0};
    e = 1;
    for(int i{0}; i < n1 - 1; ++i) e *= 5;
    for(int j{0}; j <= m2 - m1; ++j){
        int h{0};
        for(int i{0}; i < n1; ++i){
            h = h * 5 + ret[i][j];
        }
        for(int i{n1}; i < n2; ++i){
            if(h == a) ans++;
            h -= ret[i - n1][j] * e;
            h = h * 5 + ret[i][j];
        }
        if(h == a) ans++;
    }
    cout << ans << "\n";
}
 
int main() {
    fastio; 
    solve();
}