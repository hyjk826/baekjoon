// 2022-11-28
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
	int n, m;
    cin >> n >> m;
    map<int, vi> mp;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        mp[a].push_back(i + 1);
    }
    for(auto& i : mp){
        sort(i.second.begin(), i.second.end());
    }
    bool flag = true;
    vi ans;
    for(auto i{mp.rbegin()}; i != mp.rend(); i = next(i)){
        if(i->first % 7 == 0){
            if(flag){
                int l{0}, r{(int)i->second.size() - 1};
                while(l <= r){
                    ans.push_back(i->second[l]);
                    l++;
                    if(l == r + 1) break;
                    ans.push_back(i->second[r]);
                    r--;
                }
            }
            else{
                int l{0}, r{(int)i->second.size() - 1};
                while(l <= r){
                    ans.push_back(i->second[r]);
                    r--;
                    if(l == r + 1) break;
                    ans.push_back(i->second[l]);
                    l++;
                }
            }
            if(i->second.size() & 1) flag ^= 1;
        }
        else{
            if(flag){
                for(auto& j : i->second){
                    ans.push_back(j);
                }
            }
            else{
                for(int j{(int)i->second.size() -1 }; j >= 0; --j){
                    ans.push_back(i->second[j]);
                }
            }
        }
    }
    for(int i{0}; i < m; ++i){
        cout << ans[i] << "\n";
    }
}
	
