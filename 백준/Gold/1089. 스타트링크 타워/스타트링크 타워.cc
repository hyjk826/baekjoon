// 2023-01-16
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
    vector<vector<vi> > vec(10, vector<vi>(5, vi(3)));
    vec[0] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    vec[1] = {
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    };
    vec[2] = {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    };
    vec[3] = {
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    };
    vec[4] = {
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    };
    vec[5] = {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    };
    vec[6] = {
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    vec[7] = {
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    };
    vec[8] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    vec[9] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    };
    int n;
    cin >> n;
    vector<vc> board(5, vc(4 * n - 1));
    for(int i{0}; i < 5; ++i){
        for(int j{0}; j < 4 * n - 1; ++j){
            cin >> board[i][j];
        }
    }
    vector<vi> g(n);
    for(int i{0}; i < 4 * n - 1; i += 4){
        for(int a{0}; a < 10; ++a){
            bool ok = true;
            for(int j{0}; j < 5; ++j){
                for(int k{i}; k < i + 3; ++k){                    
                    if(vec[a][j][k - i] == 0 && board[j][k] == '#'){
                        ok = false;
                    }
                }
            }
            if(ok) g[i / 4].push_back(a);
        }
    }
    ll sum{0};
    ll cnt{1};
    for(int i{0}; i < n; ++i){
        cnt *= g[i].size();
    }
    function<ll(int)> ten = [&](int a){
        ll ret{1};
        for(int i{0}; i < a; ++i){
            ret *= 10;
        }
        return ret;
    };
    for(int i{0}; i < n; ++i){
        ll a{1};
        for(int j{0}; j < n; ++j){
            if(i == j) continue;
            a *= g[j].size();
        }
        for(int j{0}; j < (int)g[i].size(); ++j){
            sum += ten(n - i - 1) * g[i][j] * a;
        }
    }
    cout << fixed << setprecision(20);
    if(cnt == 0){
        cout << -1;
        return 0;
    }
    cout << 1.0 * sum / cnt;
}