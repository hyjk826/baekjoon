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
    vi mex(1001);
    mex[2] = 1;
    for(int i{3}; i <= n; ++i){
        vi ch(100);
        for(int j{0}; i - 2 - j >= 0; ++j){
            ch[mex[j] ^ mex[i - 2 - j]] = 1;
        }
        for(int j{0}; j < 100; ++j){
            if(ch[j] == 0){
                mex[i]= j; break;
            }
        }
    }
    if(mex[n]) cout << 1;
    else cout << 2;
}
