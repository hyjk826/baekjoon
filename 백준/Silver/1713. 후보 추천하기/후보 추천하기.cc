// 2022-08-31
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
    int n, m;
    cin >> n >> m;
    map<int, pi> mp;
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        if(mp.count(a)){
            mp[a].first++;
            continue;
        }
        if(mp.size() < n){
            mp[a] = {1, i};
        }
        else{
            int mn{mp.begin()->first};
            for(auto& i : mp){
                if(i.second.first < mp[mn].first){
                    mn = i.first;
                }
                else if(i.second.first == mp[mn].first){
                    if(i.second.second < mp[mn].second){
                        mn = i.first;
                    }
                }
            }
            mp.erase(mn);
            mp[a] = {1, i};
        }
    }
    for(auto& i : mp){
        cout << i.first << " ";
    }
}

