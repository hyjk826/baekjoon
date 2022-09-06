// 2022-09-06
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
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> mp;
    for(int i{1}; i <= a; ++i){
        for(int j{1}; j <= b; ++j){
            for(int k{1}; k <= c; ++k){
                mp[i + j + k]++;
            }
        }
    }
    int mx{0};
    for(auto& i : mp){
        mx = max(mx, i.second);
    }
    for(auto& i : mp){
        if(mx == i.second){
            cout << i.first;
            return 0;
        }
    }
}
	

