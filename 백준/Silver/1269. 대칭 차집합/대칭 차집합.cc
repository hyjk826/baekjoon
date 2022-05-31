// 2022-05-31
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        mp[a]++;
    }
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        mp[a]++;
    }
    int cnt{0};
    for(auto& i : mp){
        if(i.second == 2) cnt++;
    }
    cout << n - cnt + m - cnt;
}