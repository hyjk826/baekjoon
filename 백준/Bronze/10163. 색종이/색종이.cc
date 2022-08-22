// 2022-08-23
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
    int t;
    cin >> t;
    vector<vi> board(1001, vi(1001));
    int k{1};
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        for(int i{a}; i < a + c; ++i){
            for(int j{b}; j < b + d; ++j){
                board[i][j] = k;
            }
        }
        k++;
    }
    vi ch(k);
    for(int i{0}; i < 1001; ++i){
        for(int j{0}; j < 1001; ++j){
            ch[board[i][j]]++;
        }
    }
    for(int i{1}; i < k; ++i){
        cout << ch[i] << "\n";
    }
}

