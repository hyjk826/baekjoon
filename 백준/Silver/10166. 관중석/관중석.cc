// 2022-12-18
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
	fastio;
    int a, b;
    cin >> a >> b;
    vector<vector<bool>> ch(b + 1, vector<bool>(b + 1));
    for(int i{a}; i <= b; ++i){
        for(int j{1}; j <= i; ++j){
            int g = gcd(j, i);
            ch[j / g][i / g] = 1;
        }
    }
    int ans{0};
    for(int i{0}; i <= b; ++i){
        for(int j{0}; j <= b; ++j){
            if(ch[i][j]) ans++;
        }
    }
    cout << ans;
}
	
