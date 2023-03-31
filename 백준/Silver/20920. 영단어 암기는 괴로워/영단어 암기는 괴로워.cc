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
    int n, k;
    cin >> n >> k;
    vs vec;
    unordered_map<string, int> mp;
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        if(str.size() < k) continue;
        if(!mp.count(str)) vec.push_back(str);
        mp[str]++;
    }
    sort(vec.begin(), vec.end(), [&](string& a, string& b){
        if(mp[a] == mp[b]){
            if(a.size() == b.size()) return a < b;
            else return a.size() > b.size();
        }
        else return mp[a] > mp[b];  
    });
    for(auto& i : vec) cout << i << "\n";
}
