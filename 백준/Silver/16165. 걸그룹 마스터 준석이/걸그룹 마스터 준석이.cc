// 2022-12-12
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
    int n, q;
    cin >> n >> q;
    map<string, vs> mp1;
    map<string, string> mp2;
    for(int i{0}; i < n; ++i){
        string team;
        cin >> team;
        int m;
        cin >> m;
        for(int j{0}; j < m; ++j){
            string str;
            cin >> str;
            mp1[team].push_back(str);
            mp2[str] = team;
        }
    }
    for(auto& i : mp1){
        sort(i.second.begin(), i.second.end());
    }
    while(q--){
        string str;
        int a;
        cin >> str  >> a;
        if(a == 0){
            for(auto& i : mp1[str]){
                cout << i << "\n";
            }
        }
        else{
            cout << mp2[str] << "\n";
        }
    }

}
	
