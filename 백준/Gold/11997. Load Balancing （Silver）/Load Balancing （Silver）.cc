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
    int n;
    cin >> n;
    vp vec(n);
    vi A, B;
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
        A.push_back(vec[i].first);
        B.push_back(vec[i].second);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<vi> board((int)A.size() + 2, vi((int)B.size() + 2));
    for(int i{0}; i < n; ++i){
        vec[i].first = lower_bound(A.begin(), A.end(), vec[i].first) - A.begin() + 1;
        vec[i].second = lower_bound(B.begin(), B.end(), vec[i].second) - B.begin() + 1;
        board[vec[i].first][vec[i].second]++;
    }
    for(int i{1}; i <= (int)A.size() + 1; ++i){
        for(int j{1}; j <= (int)B.size() + 1; ++j){
            board[i][j] += board[i][j - 1];
        }
    }
    for(int j{1}; j <= (int)B.size() + 1; ++j){
        for(int i{1}; i <= (int)A.size() + 1; ++i){
            board[i][j] += board[i - 1][j];
        }
    }
    function<int(int,int,int,int)> f = [&](int x1, int y1, int x2, int y2){
        int ret{0};
        ret += board[x2][y2];
        ret -= board[x1 - 1][y2];
        ret -= board[x2][y1 - 1];
        ret += board[x1 - 1][y1 - 1];
        return ret;
    };
    int ans{MAX};
    for(int i{1}; i <= (int)A.size(); ++i){
        for(int j{1}; j <= (int)B.size(); ++j){
            int mx{0};
            mx = max(mx, f(1, 1, i, j));
            mx = max(mx, f(1, j + 1, i, (int)B.size()));
            mx = max(mx, f(i + 1, 1, (int)A.size(), j));
            mx = max(mx, f(i + 1, j + 1, (int)A.size(), (int)B.size()));
            ans = min(ans, mx);
        }
    }
    cout << ans;
}
