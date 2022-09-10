// 2022-09-10
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n;
int board[128][128];
int zero{0}, one{0};

void f(int x, int y, int k){
    int sum{0};
    for(int i{x}; i < x + k; ++i){
        for(int j{y}; j < y + k; ++j){
            sum += board[i][j];
        }
    }
    if(sum == k * k){
        one++;
    }
    else if(sum == 0){
        zero++;
    }
    else{
        f(x, y, k / 2);
        f(x, y + k / 2, k / 2);
        f(x + k / 2, y, k / 2);
        f(x + k / 2, y + k / 2, k / 2);
    }
}
int main(){
    fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    f(0, 0, n);
    cout << zero << "\n" << one;   
}