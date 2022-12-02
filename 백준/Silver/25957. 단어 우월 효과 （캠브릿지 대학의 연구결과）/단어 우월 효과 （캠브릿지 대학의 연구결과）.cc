// 2022-12-02
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
    map<string, string> mp;
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        string c = str;
        if(str.size() > 2){
            sort(c.begin() + 1, c.begin() + (int)str.size() - 1);
        }
        mp[c] = str;
    }
    int m;
    cin >> m;
    for(int i{0}; i < m; ++i){
        string str;
        cin >> str;
        if(str.size() > 2){
            sort(str.begin() + 1, str.begin() + (int)str.size() - 1);
        }
        cout << mp[str] << " ";
    }
}
	
