// 2022-07-07
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vector<vi> floyd(n, vi(n, MAX));
    vector<vi> nx(n, vi(n, -1));
    for(int i{0}; i < n; ++i){
        floyd[i][i] = 0;
    }
    for(int i{0}; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(floyd[a][b] > c){
            floyd[a][b] = c;
            nx[a][b] = b;
        }
    }
    for(int k{0}; k < n; ++k){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                if(floyd[i][j] > floyd[i][k] + floyd[k][j]){
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                    nx[i][j] = nx[i][k];
                }
            }
        }
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(floyd[i][j] == MAX) cout << 0 << " ";
            else cout << floyd[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            if(floyd[i][j] == MAX || floyd[i][j] == 0){
                cout << 0 << "\n";
                continue;
            }
            vi path;
            for(int k{i}; k != j; k = nx[k][j]) path.push_back(k);
            path.push_back(j);
            cout << path.size() << " ";
            for(auto& k : path) cout << k + 1 << " ";
            cout << "\n";
        }
    }
}   
