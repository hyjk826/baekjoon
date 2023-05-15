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

int dp[50][51][51][3][3]{};

int main(){
	fastio;
    int a, b, c;
    a = b = c = 0;
    string str;
    cin >> str;
    for(auto& i : str){
        if(i == 'A') a++;
        if(i == 'B') b++;
        if(i == 'C') c++;
    }
    string ans = string((int)str.size(), 'A');
    function<void(int,int,int,int,int)> f = [&](int x, int y, int z, int q, int w){
        if(y < 0 || z < 0) return;
        if(x == (int)str.size()){
            if(y == 0 && z == 0) {
                cout << ans; exit(0);
            }            
        }
        else{
            if(dp[x][y][z][q][w]) return;
            dp[x][y][z][q][w] = 1;
            f(x + 1, y, z, w, 0);
            if(x == 0 || ans[x - 1] != 'B') {
                ans[x] = 'B';
                f(x + 1, y - 1, z, w, 1);
                ans[x] = 'A';
            }
            if(x == 0){
                ans[x] = 'C';
                f(x + 1, y, z - 1, w, 2);
                ans[x] = 'A';
            }
            else if(x == 1){
                if(ans[x - 1] != 'C') {
                    ans[x] = 'C';
                    f(x + 1, y, z - 1, w, 2);
                    ans[x] = 'A';
                }
            }
            else{
                if(ans[x - 1] != 'C' && ans[x - 2] != 'C'){
                    ans[x] = 'C';
                    f(x + 1, y, z - 1, w, 2);
                    ans[x] = 'A';
                }
            }

        }
    };
    f(0, b, c, 0, 0);
    cout << -1;
}
