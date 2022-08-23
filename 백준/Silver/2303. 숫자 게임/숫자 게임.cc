// 2022-08-23
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
    int mx{0};
    int index{-1};
    for(int i{0}; i < n; ++i){
        vi vec(5);
        for(int j{0}; j < 5; ++j){
            cin >> vec[j];
        }
        int m{0};
        for(int a{0}; a < 5; ++a){
            for(int b{a + 1}; b < 5; ++b){
                for(int c{b + 1}; c < 5; ++c){
                    m = max(m, (vec[a] + vec[b] + vec[c]) % 10);
                }
            }
        }
        if(mx <= m){
            mx = m;
            index = i;
        }
    }
    cout << index + 1;
}

