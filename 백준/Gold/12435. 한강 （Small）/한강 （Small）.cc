// 2022-08-17
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

vi cnt(1000000);
vi mn(1000000, -1);

int main() {
	fastio;
    for(int i{2}; i <= 1000000; ++i){
        for(int j{i * 2}; j <= 1000000; j += i){
            cnt[j]++;
            if(mn[j] == -1) mn[j] = i;
        }
    }
    map<int, vi> mp;
    for(int i{1}; i <= 1000000; ++i){
        mp[cnt[i]].push_back(i);
    }
    int t;
    cin >> t;
    for(int i{1}; i <= t; ++i){
        int n, m;
        cin >> n >> m;
        int k = cnt[n];
        int ans{0};
        for(auto& i : mp[k]){
            if(i >= n) break;
            if(mn[i] >= m) ans++;
        }
        cout << "Case #" << i << ": ";
        cout << ans << "\n";
    }
}