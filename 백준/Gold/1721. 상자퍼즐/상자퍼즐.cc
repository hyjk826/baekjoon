// 2022-08-17
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

int n;
vector<vi> vec(26, vi(5));
vi ch(26);
int xx[]{-1,0};
int yy[]{0,-1};

void dfs(int L, vector<vi>& ans, vector<vi>& r){
    if(L == n * n){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                cout << vec[ans[i][j]][0] << " ";
            }
            cout << "\n";
        }
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                cout << r[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    else{
        int x = L / n;
        int y = L % n;
        for(int i{1}; i <= n * n; ++i){
            if(ch[i] == 1) continue;
            for(int j{1}; j <= 4; ++j){
                bool flag = true;
                rotate(vec[i].begin() + 1, vec[i].begin() + 4, vec[i].end());
                for(int dir{0}; dir < 2; ++dir){
                    int nx = x + xx[dir];
                    int ny = y + yy[dir];
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1){
                        continue;
                    }
                    else{
                        if(dir == 0){
                             if(vec[ans[nx][ny]][3] != vec[i][1]){
                                flag = false;
                                break;
                             }
                        }
                        else{
                            if(vec[ans[nx][ny]][2] != vec[i][4]){
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if(x == 0 && vec[i][1] != 0) flag = false;                
                if(y == n - 1 && vec[i][2] != 0) flag = false;
                if(x == n - 1 && vec[i][3] != 0) flag = false;
                if(y == 0 && vec[i][4] != 0) flag = false;
                if(flag){
                    ch[i] = 1;
                    ans[x][y] = i;
                    r[x][y] = j % 4;
                    dfs(L + 1, ans, r);
                    ch[i] = 0;
                }
            }
        }
    }
}


int main() {
	fastio;
    cin >> n;    
    for(int i{1}; i <= n * n; ++i){
        for(int j{0}; j < 5; ++j){
            cin >> vec[i][j];
        }
    }
    vector<vi> ans(n, vi(n));
    vector<vi> r(n, vi(n));
    dfs(0, ans, r);
}

