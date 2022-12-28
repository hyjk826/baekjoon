// 2022-07-24
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vs vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        bool f = 1;
        sort(vec.begin(), vec.end());
        for(int i{1}; i < n; ++i){
            if(vec[i].size() >= vec[i - 1].size()){
                if(vec[i].substr(0, vec[i - 1].size()) == vec[i - 1]){
                    f = 0;
                    break;
                }
            }
        }
        if(f) cout << "YES\n";
        else cout << "NO\n";
    }
}

