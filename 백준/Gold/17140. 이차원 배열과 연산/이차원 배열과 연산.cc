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

int main() {
	fastio;
    int r, c, k;
    cin >> r >> c >> k;
    r--;
    c--;
    vector<vi> board(100, vi(100));
    for(int i{0}; i < 3; ++i){
        for(int j{0}; j < 3; ++j){
            cin >> board[i][j];
        }
    }
    int time{0};
    int n, m;
    n = m = 3;
    while(1){
        if(board[r][c] == k){
            cout << time;
            return 0;
        }
        time++;
        if(time == 101) break;
        if(n >= m){
            int mx{0};
            for(int i{0}; i < n; ++i){
                map<int, int> mp;
                for(int j{0}; j < m; ++j){
                    mp[board[i][j]]++;
                }
                vp vec;
                for(auto& j : mp){
                    if(j.first == 0) continue;
                    vec.push_back({j.first, j.second});
                }
                sort(vec.begin(), vec.end(), [&](pi a, pi b){
                    if(a.second == b.second) return a.first < b.first;
                    return a.second < b.second;
                });
                for(int j{0}; j < (int)vec.size() && j < 50; ++j){
                    board[i][j * 2] = vec[j].first;
                    board[i][j * 2 + 1] = vec[j].second;
                }
                for(int j{min(100, (int)vec.size() * 2)}; j < 100; ++j){
                    board[i][j] = 0;
                }
                mx = max(mx, (int)vec.size() * 2);
            }
            m = mx;
        }
        else{
            int mx{0};
            for(int j{0}; j < m; ++j){
                map<int, int> mp;
                for(int i{0}; i < n; ++i){
                    mp[board[i][j]]++;
                }
                vp vec;
                for(auto& i : mp){
                    if(i.first == 0) continue;
                    vec.push_back({i.first, i.second});
                }
                sort(vec.begin(), vec.end(), [&](pi a, pi b){
                    if(a.second == b.second) return a.first < b.first;
                    return a.second < b.second;
                });
                for(int i{0}; i < (int)vec.size() && i < 50; ++i){
                    board[i * 2][j] = vec[i].first;
                    board[i * 2 + 1][j] = vec[i].second;
                }
                for(int i{min(100, (int)vec.size() * 2)}; i < 100; ++i){
                    board[i][j] = 0;
                }
                mx = max(mx, (int)vec.size() * 2);
            }
            n = mx;
        }
        // cout << n << " " << m << "\n";
        // for(int i{0}; i < 100; ++i){
        //     for(int j{0}; j < 100; ++j){
        //         if(board[i][j] == 0) break;
        //         cout << board[i][j] << " ";
        //     }
        //     if(board[i][0] == 0) break;
        //     cout << "\n";
        // }
        // cout << "\n";
    }
    cout << -1;
}

