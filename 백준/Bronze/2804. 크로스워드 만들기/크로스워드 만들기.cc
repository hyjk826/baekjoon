// 2022-08-21
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

int main(){
    fastio;
	string s, t;
    cin >> s >> t;
    vector<vc> board((int)t.size(), vc((int)s.size(), '.'));
    for(int i{0}; i < (int)s.size(); ++i){
        for(int j{0}; j < (int)t.size(); ++j){
            if(s[i] == t[j]){
                for(int k{0}; k < (int)s.size(); ++k){
                    board[j][k] = s[k];
                }
                for(int k{0}; k < (int)t.size(); ++k){
                    board[k][i] = t[k];
                }
                for(int a{0}; a < (int)t.size(); ++a){
                    for(int b{0}; b < (int)s.size(); ++b){
                        cout << board[a][b];
                    }
                    cout << "\n";
                }
                return 0;
            }
        }
    }
}