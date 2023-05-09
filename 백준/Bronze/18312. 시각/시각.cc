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
    int n, a;
    cin >> n >> a;
    int cnt{0};
    for(int i{0}; i <= n; ++i){
        for(int j{0}; j < 60; ++j){
            for(int k{0}; k < 60; ++k){
                bool ok = false;
                ok |= (i / 10 == a);
                ok |= (i % 10 == a);
                ok |= (j / 10 == a);
                ok |= (j % 10 == a);
                ok |= (k / 10 == a);
                ok |= (k % 10 == a);
                if(ok) cnt++;
            }
        }
    }
    cout << cnt;
}
