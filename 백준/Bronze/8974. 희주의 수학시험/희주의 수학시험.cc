// 2022-09-21
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
    vi vec;
    for(int i{1};;++i){
        for(int j{0}; j < i; ++j){
            vec.push_back(i);
            if(vec.size() >= 1000) break;
        }
        if(vec.size() >= 1000) break;
    }
    int ans{0};
    int a, b;
    cin >> a >> b;
    a--;
    for(int i{a}; i < b; ++i) ans += vec[i];
    cout << ans;
}
	

