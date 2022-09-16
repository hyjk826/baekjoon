// 2022-09-16
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
    int n;
    cin >> n;
    string str;
    cin >> str;
    str = ' ' + str;
    vc arr = {'T', 'G', 'F', 'P'};
    vector<vi> board(4, vi(n + 1));
    for(int i{0}; i < 4; ++i){
        for(int j{1}; j <= n; ++j){
            board[i][j] = board[i][j - 1];
            if(str[j] == arr[i]) board[i][j]++;
        }
    }
    vi vec(n + 1);
    map<int, int> mp;
    mp[0]++;
    for(int i{1}; i <= n; ++i){
        int k{1};
        int sum{0};
        for(int j{0}; j < 4; ++j){
            sum += (board[j][i] % 3) * k;
            k *= 3;
        }
        mp[sum]++;
    }
    ll ans{0};
    for(auto& i : mp){
        ans += 1LL * (i.second - 1) * i.second / 2;
    }
    cout << ans;
}
	

