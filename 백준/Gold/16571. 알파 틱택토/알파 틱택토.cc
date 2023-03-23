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
    map<vector<vi>, int> mp;
    string a;
    vector<vi> board(3, vi(3));
    for(int i{0}; i < 3; ++i){
        for(int j{0}; j < 3; ++j){
            cin >> board[i][j];
        }
    }
    function<int(vector<vi>)> f = [&](vector<vi> board){
        if(mp.count(board)) return mp[board];
        int a{0}, b{0};
        for(int i{0}; i < 3; ++i){
            for(int j{0}; j < 3; ++j){
                if(board[i][j] == 1) a++;
                else if(board[i][j] == 2) b++;
            }
        }
        bool f1 = false;
        bool f2 = false;
        for(int i{0}; i < 3; ++i){
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
                if(board[i][0] == 1) f1 = true;
                if(board[i][0] == 2) f2 = true;
            }
        }
        for(int j{0}; j < 3; ++j){
            if(board[0][j] == board[1][j] && board[1][j] == board[2][j]){
                if(board[0][j] == 1) f1 = true;
                if(board[0][j] == 2) f2 = true;
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            if(board[1][1] == 1) f1 = true;
            if(board[1][1] == 2) f2 = true;
        }
        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[1][1] == 1) f1 = true;
            if(board[1][1] == 2) f2 = true;
        }
        if(f1 || f2) return mp[board] = 0;
        if(a + b == 9) return mp[board] = 2;
        bool ok = false;
        bool draw = false;
        if(a == b){            
            for(int i{0}; i < 3; ++i){
                for(int j{0}; j < 3; ++j){
                    if(board[i][j] == 0){
                        board[i][j] = 1;
                        ok |= (f(board) == 0);
                        draw |= (f(board) == 2);
                        board[i][j] = 0;
                    }
                }
            }
        }
        else if(a > b){
            for(int i{0}; i < 3; ++i){
                for(int j{0}; j < 3; ++j){
                    if(board[i][j] == 0){
                        board[i][j] = 2;
                        ok |= (f(board) == 0);
                        draw |= (f(board) == 2);
                        board[i][j] = 0;
                    }
                }
            }
        }
        if(ok) return mp[board] = 1;
        else if(draw) return mp[board] = 2;
        else return mp[board] = 0;
    };
    if(f(board) == 0) cout << "L";
    else if(f(board) == 1) cout << "W";
    else cout << "D"; 
}
