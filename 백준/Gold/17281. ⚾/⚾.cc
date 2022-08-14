// 2022-08-14
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
    vector<vi> board(n, vi(9));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 9; ++j){
            cin >> board[i][j];
        }
    }
    vi vec;
    int ans{0};
    for(int i{0}; i < 9; ++i) vec.push_back(i);
    do{
        if(vec[3] != 0) continue;
        int sum{0};
        int s = 0;
        for(int inning{0}; inning < n; ++inning){
            vi ch(3);
            int out{0};
            while(out < 3){
                int k = vec[s];
                int a = board[inning][k];
                if(a == 1){
                    sum += ch[2];
                    ch[2] = ch[1];
                    ch[1] = ch[0];
                    ch[0] = 1;
                }
                else if(a == 2){
                    sum += ch[1] + ch[2];
                    ch[1] = 1;
                    ch[2] = ch[0];
                    ch[0] = 0;
                }
                else if(a == 3){
                    sum += ch[0] + ch[1] + ch[2];
                    ch[0] = ch[1] = 0;
                    ch[2] = 1;
                }
                else if(a == 4){
                    sum += ch[0] + ch[1] + ch[2] + 1;
                    ch[0] = ch[1] = ch[2] = 0;
                }
                else{
                    out++;
                }
                s = (s + 1) % 9;
            }
        }
        ans = max(ans, sum);
    }while(next_permutation(vec.begin(), vec.end()));
    cout << ans << "\n";
}

