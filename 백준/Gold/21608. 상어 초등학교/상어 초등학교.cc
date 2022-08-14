// 2022-08-14
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

struct st{
    int x, y, good, empty;
};

int main() {
	fastio;
    int n;
    cin >> n;
    vector<vi> vec(n * n, vi(5));
    vi ch(n * n + 1);
    for(int i{0}; i < n * n; ++i){
        for(int j{0}; j < 5; ++j){
            cin >> vec[i][j];
            if(j == 0){
                ch[vec[i][j]] = i;
            }
        }
    }
    vector<vi> board(n, vi(n));
    int ans{0};
    int xx[]{-1,0,1,0};
    int yy[]{0,1,0,-1};
    for(int i{0}; i < n * n; ++i){
        vector<st> A;
        for(int j{0}; j < n; ++j){
            for(int k{0}; k < n; ++k){
                if(board[j][k] == 0){
                    int good{0}, empty{0};
                    for(int dir{0}; dir < 4; ++dir){
                        int nx = j + xx[dir];
                        int ny = k + yy[dir];
                        if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                        if(board[nx][ny] == 0) empty++;
                        else{
                            bool flag = false;
                            for(int l{1}; l <= 4; ++l){
                                if(board[nx][ny] == vec[i][l]){
                                    flag = true;
                                    break;
                                }
                            }
                            if(flag) good++;
                        }
                    }
                    A.push_back({j, k, good, empty});                    
                }
            }
        }
        sort(A.begin(), A.end(), [&](st a, st b){
            if(a.good == b.good){
                if(a.empty == b.empty){
                    if(a.x == b.x){
                        return a.y < b.y;
                    }
                    else return a.x < b.x;
                }
                else return a.empty > b.empty;
            }
            else return a.good > b.good;
        });
        board[A[0].x][A[0].y] = vec[i][0];
    }
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            int index = ch[board[i][j]];
            int cnt{0};
            for(int dir{0}; dir < 4; ++dir){
                int nx = i + xx[dir];
                int ny = j + yy[dir];
                if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                bool flag = false;
                for(int k{1}; k <= 4; ++k){
                    if(board[nx][ny] == vec[index][k]){
                        flag = true;
                        break;
                    }
                }
                if(flag) cnt++;
            }
            if(cnt == 1) ans += 1;
            else if(cnt == 2) ans += 10;
            else if(cnt == 3) ans += 100;
            else if(cnt == 4) ans += 1000;
        }
    }
    cout << ans;
}

