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
    vector<vc> board(n, vc(n));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < n; ++j){
            cin >> board[i][j];
        }
    }
    int op;
    cin >> op;
    if(op == 1){
        for(int i{0}; i < n; ++i){
            for(int j{0}; j < n; ++j){
                cout << board[i][j];
            }            
            cout << "\n";
        }
        
    }
    else if(op == 2){
        for(int i{0}; i < n; ++i){
            for(int j{n - 1}; j >= 0; --j){
                cout << board[i][j];
            }            
            cout << "\n";
        }
        
    }
    else{
        for(int i{n - 1}; i >= 0; --i){
            for(int j{0}; j < n; ++j){
                cout << board[i][j];
            }          
            cout << "\n";  
        }
    }
}
