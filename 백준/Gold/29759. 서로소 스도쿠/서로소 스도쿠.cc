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

vi prime(1000001);
vi tmp;
vi k;

void init(){
    prime[1] = 1;
    for(ll i{2}; i <= (int)1e6; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= (int)1e6; j += i){
            prime[j] = 1;
        }
    }    
}

void solve(){    
	int n;
    cin >> n;
    vector<vi> board(n * n, vi(n * n));
    for(int i{0}; i < n * n; ++i){
        for(int j{0}; j < n * n; ++j){
            cin >> board[i][j];
            if(board[i][j]) {
                for(int a{1}; a * a <= board[i][j]; ++a){
                    if(board[i][j] % a == 0){
                        int x = a;
                        int y = board[i][j] / a;
                        prime[x] = prime[y] = 1;
                    }
                }
            }
        }
    }
    for(int i{1}; i <= (int)1e6; ++i){
        if(prime[i] == 0) tmp.push_back(i);
        if(tmp.size() >= 10000) break;
    }
    int idx{0};
    for(int i{0}; i < n * n; ++i){
        for(int j{0}; j < n * n; ++j){
            if(board[i][j] == 0){
                board[i][j] = tmp[idx++];
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
	fastio;
    init();
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
