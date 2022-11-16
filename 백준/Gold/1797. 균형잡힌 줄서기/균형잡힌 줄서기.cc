// 2022-11-16
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

int main() {
	fastio;
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a == 0) mp[b]++;
        else mp[b]--;
    }
    int pre{-MAX};
    map<int, set<pi>> A;
    A[0].insert({0, mp.begin()->first});
    for(auto i{mp.begin()}; i != mp.end(); ++i){
        if(pre != -MAX){
            i->second += pre;
        }
        pre = i->second;
        if(next(i) != mp.end()){
            A[i->second].insert({i->first, next(i)->first});
        }
        else A[i->second].insert({i->first, MAX});
    }   
    int ans{0}; 
    for(auto& i : A){
        auto& st = i.second;
        ans = max(ans, prev(st.end())->first - (st.begin())->second);
    }
    cout << ans;
}
	

