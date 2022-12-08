// 2022-12-08
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

int main() {
	fastio;
	int n;
    cin >> n;
    vector<vc> board(7, vc(n));
    for(int i{0}; i < 7; ++i){
        int k = (1 << i);
        int a, b;
        a = b = 0;
        for(int j{0}; j < n; ++j){
            if((j / k) & 1){
                board[i][j] = 'B';
                a++;
            }
            else{
                board[i][j] = 'A';
                b++;
            }
        }
        if(n <= k) board[i].back() = 'B';
    }
    for(int i{0}; i < 7; ++i){
        for(int j{0}; j < n; ++j){
            cout << board[i][j];
        }
        cout << "\n";
    }
}
	
