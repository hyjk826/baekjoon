// 2022-07-28
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

vector<vi> board;

void f(int a, int b, int c, int d, vector<vi>& copy){
    int k = copy[a][d];
    for(int j{d}; j > b; --j){
        copy[a][j] = copy[a][j - 1];
    }
    for(int i{a}; i < c; ++i){
        copy[i][b] = copy[i + 1][b];
    }
    for(int j{b}; j < d; ++j){
        copy[c][j] = copy[c][j + 1];
    }
    for(int i{c}; i > a; --i){
        copy[i][d] = copy[i - 1][d];
    }
    copy[a + 1][d] = k;
}

struct st{
    int a, b, c;
};

int main() {
	fastio;
    int n, m, q;
    cin >> n >> m >> q;
    board.resize(n, vi(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int ans{MAX};
    vi vec;
    vector<st> s(q);
    for(int i{0}; i < q; ++i){
        vec.push_back(i);
        cin >> s[i].a >> s[i].b >> s[i].c;
        s[i].a--;
        s[i].b--;
    }
    do{
        vector<vi> copy;
        copy = board;
        for(int i{0}; i < (int)vec.size(); ++i){
            for(int j{1}; j <= s[vec[i]].c; ++j){
                int a = s[vec[i]].a;
                int b = s[vec[i]].b;
                f(a - j, b - j, a + j, b + j, copy);
            }
        }
        for(int i{0}; i < n; ++i){
            int sum{0};
            for(int j{0}; j < m; ++j){
                sum += copy[i][j];
            }
            ans = min(ans, sum);
        }
    }while(next_permutation(vec.begin(), vec.end()));
    cout << ans;
}

