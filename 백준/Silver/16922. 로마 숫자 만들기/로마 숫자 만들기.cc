// 2022-08-15
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
    set<int> s;
    for(int i{0}; i <= n; ++i){
        for(int j{0}; j <= n; ++j){
            for(int k{0}; k <= n; ++k){
                for(int l{0}; l <= n; ++l){
                    if(i + j + k + l == n){
                        s.insert(i + j * 5 + k * 10 + l * 50);
                    }
                }
            }
        }
    }
    cout << s.size();
}