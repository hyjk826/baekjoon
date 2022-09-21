// 2022-09-21
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
    int ans{0};
    int n, m;
    cin >> n >> m;
    vector<vc> board(n, vc(m));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            cin >> board[i][j];
        }
    }
    for(int i{0}; i < (1 << (n * m)); ++i){
        vector<vi> ch(n, vi(m));
        for(int j{0}; j < n * m; ++j){
            if((i >> j) & 1){
                ch[j / m][j % m] = 1;
            }
        }
        
        int sum{0};
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < m; ++k){
                if(ch[j][k] != -1){
                    if(ch[j][k] == 0){
                        string str;
                        for(int a{k}; a < m; ++a){
                            if(ch[j][a] == 0){
                                str += board[j][a];
                                ch[j][a] = -1;
                            }
                            else break;
                        }
                        sum += stoi(str);
                    }
                    else if(ch[j][k] == 1){
                        string str;
                        for(int a{j}; a < n; ++a){
                            if(ch[a][k] == 1){
                                str += board[a][k];
                                ch[a][k] = -1;
                            }
                            else break;
                        }
                        sum += stoi(str);
                    }
                }
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
}
	

