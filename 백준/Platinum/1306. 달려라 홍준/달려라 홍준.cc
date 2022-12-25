// 2022-12-26
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
    int n, m;
    cin >> n >> m;
    vi vec(n);
    for(int i{0}; i < n; ++i) {
        cin >> vec[i];
    }
    map<int, int> mp;
    for(int i{0}; i < 2 * m - 1; ++i){
        mp[vec[i]]++;
    }
    cout << prev(mp.end())->first << " ";
    for(int i{0}; i + 2 * m - 1 < n; ++i){
        mp[vec[i]]--;
        if(mp[vec[i]] == 0) mp.erase(vec[i]);
        mp[vec[i + 2 * m - 1]]++;
        cout << prev(mp.end())->first << " ";
    }
}
