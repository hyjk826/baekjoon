// 2022-07-25
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

int main() {
	fastio;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> add(n, vi(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> add[i][j];
        }
    }
    map<int, int> alive[10][10];
    multiset<int> temp[10][10];
    int five[10][10]{};
    int plus[10][10]{};
    vector<vi> A(n, vi(n, 5));
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        alive[a][b][c]++;
    }
    int xx[]{-1,-1,-1,0,0,1,1,1};
    int yy[]{-1,0,1,-1,1,-1,0,1};
    for(int year{0}; year < k; ++year){
        for(int p{0}; p < 4; ++p){
            if(p == 0){
                for(int i{0}; i < n; ++i){
                    for(int j{0}; j < n; ++j){
                        vp v;
                        for(auto& k : alive[i][j]){
                            if(k.second == 0) continue;
                            int a = min(k.second, A[i][j] / k.first);
                            A[i][j] -= a * k.first;
                            plus[i][j] += k.first / 2 * (k.second - a);
                            k.second = 0;
                            v.push_back({k.first + 1, a});
                            if((k.first + 1) % 5 == 0) five[i][j] += a;
                        }
                        for(auto& k : v){
                            alive[i][j][k.first] += k.second;
                        }
                    }
                }
            }
            else if(p == 1){
                for(int i{0}; i < n; ++i){
                    for(int j{0}; j < n; ++j){
                        A[i][j] += plus[i][j];
                        plus[i][j] = 0;
                    }
                }
            }
            else if(p == 2){
                for(int i{0}; i < n; ++i){
                    for(int j{0}; j < n; ++j){
                        for(int dir{0}; dir < 8; ++dir){
                            int nx = i + xx[dir];
                            int ny = j + yy[dir];
                            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                            alive[nx][ny][1] += five[i][j];
                        }
                        five[i][j] = 0;
                    }
                }
            }
            else if(p == 3){
                for(int i{0}; i < n; ++i){
                    for(int j{0}; j < n; ++j){
                        A[i][j] += add[i][j];
                    }
                }
            }
        }
    }
    ll ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            for(auto& k : alive[i][j]) ans += k.second;
        }
    }
    cout << ans;
}

