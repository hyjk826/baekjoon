// 2023-01-09
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, int> mp;
        for(int i{0}; i < n; ++i){
            string str;
            cin >> str;
            mp[str]++;
        }
        vs A;
        for(auto& i : mp){
            for(int j{0}; j < min(3, i.second); ++j){
                A.push_back(i.first);
            }
        }
        int ans{MAX};
        for(int i{0}; i < (int)A.size(); ++i){
            for(int j{i + 1}; j < (int)A.size(); ++j){
                for(int k{j + 1}; k < (int)A.size(); ++k){
                    string x = A[i];
                    string y = A[j];
                    string z = A[k];
                    int sum{0};
                    for(int a{0}; a < 4; ++a){
                        if(x[a] != y[a]) sum++;
                        if(y[a] != z[a]) sum++;
                        if(x[a] != z[a]) sum++;
                    }
                    ans = min(ans, sum);
                }
            }
        }
        cout << ans << "\n";
    }
}
