// 2022-11-14
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

int ch[11][11][11][11]{};

void f(string str){
    for(int i{0}; i < (1 << 4); ++i){
        vi A(4);
        for(int j{0}; j < 4; ++j){
            if((i >> j) & 1){
                A[j] = str[j] - '0';
            }
            else{
                A[j] = 10;
            }
        }
        ch[A[0]][A[1]][A[2]][A[3]]++;
    }
}

// 1235 7133
int main() {
	fastio;    
    int n;
    cin >> n;
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    f(vec[0]);
    ll ans{0};
    for(int i{1}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            vector<vi> g(4);
            vi A(4, 10);
            for(int k{0}; k < 4; ++k){
                if(vec[i][k] == vec[j][k]){
                    g[k].push_back(vec[j][k] - '0');
                    A[k] = vec[j][k] - '0';
                }   
                else{
                    g[k].push_back(10);
                    g[k].push_back(vec[i][k] - '0');
                    g[k].push_back(vec[j][k] - '0');
                }
            }
            for(auto& a : g[0]){
                for(auto& b : g[1]){
                    for(auto& c : g[2]){
                        for(auto& d : g[3]){
                            int cnt{0};
                            if(g[0].size() == 3 && a != 10) cnt++;
                            if(g[1].size() == 3 && b != 10) cnt++;
                            if(g[2].size() == 3 && c != 10) cnt++;
                            if(g[3].size() == 3 && d != 10) cnt++;
                            if(cnt & 1){
                                ans -= ch[a][b][c][d];
                            }
                            else{
                                ans += ch[a][b][c][d];
                            }
                        }
                    }
                }
            }   
        }
        f(vec[i]);
    }
    cout << ans;
}
	

