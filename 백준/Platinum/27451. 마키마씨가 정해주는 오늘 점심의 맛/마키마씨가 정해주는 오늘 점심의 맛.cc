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

struct st{
    int x, y, z;
};

int main(){
	fastio;
    int n, m;
    cin >> n >> m;
    queue<st> Q;
    int a, b, c;
    cin >> a >> b >> c;
    st ch[45][45][45];
    for(int i{1}; i <= n; ++i){
        for(int j{1}; j <= n; ++j){
            for(int k{1}; k <= n; ++k){
                ch[i][j][k] = {-2,-2,-2};
            }
        }
    }
    Q.push({a, b, c});
    ch[a][b][c] = {-1,-1,-1};
    vector<vi> g(n + 1);
    for(int i{0}; i < m; ++i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vi A, B, C;
    int city{-1};
    while(!Q.empty()){
        int x{Q.front().x};
        int y{Q.front().y};
        int z{Q.front().z};
        Q.pop();
        if(x == y && y == z && z == x){
            city = x;
            while(1){
                if(x == -1) break;
                A.push_back(x);
                B.push_back(y);
                C.push_back(z);
                auto pre = ch[x][y][z];
                x = pre.x;
                y = pre.y;
                z = pre.z;
            }
            break;
        }
        for(auto& i : g[x]){
            for(auto& j : g[y]){
                for(auto& k : g[z]){
                    if(ch[i][j][k].x == -2){
                        ch[i][j][k] = {x, y, z};
                        Q.push({i, j, k});
                    }
                }
            }
        }
    }
    if(city == -1){
        cout << -1; return 0;
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    cout << city << " " << A.size() - 1 << "\n";
    for(auto& i : A) cout << i << " ";
    cout << "\n";
    for(auto& i : B) cout << i << " ";
    cout << "\n";
    for(auto& i : C) cout << i << " ";
    cout << "\n";
}
