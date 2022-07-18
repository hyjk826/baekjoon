// 2022-07-17
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
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
    vi vec(n);
    int zero{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        if(vec[i] == 0) zero++;
    }
    map<int, int> m;
    for(int i{0}; i < n - 1; ++i){
        for(int j{i + 1}; j < n; ++j){
            m[vec[i] + vec[j]]++;
        }
    }
    int ans{0};
    for(int i{0}; i < n; ++i){
        int a = m[vec[i]];
        if(vec[i] == 0){
            if(a == zero - 1) continue;
        }
        else{
            if(a == zero) continue;
        }
        ans++;
    }
    cout << ans;
}
